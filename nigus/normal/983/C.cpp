#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,q,p;
ll T;


ll enter[2001] = {0};
ll out[2001] = {0};

const ll base = 12834857;
unordered_map<ll,ll> M;

ll dp(ll i, ll nex, vl bus){

    sort(all(bus));

    ll h = base*i+nex;
    bool ful = 1;
    bool emp = 1;
    for(int c1 = 0; c1 < sz(bus); c1++){
        h *= base;
        h += bus[c1];
        if(bus[c1] == -1)ful = 0;
        if(bus[c1] != -1)emp = 0;
    }

    if(emp && nex == n)return 0;

    if(M.find(h) != M.end())return M[h];

    ll up = big;
    ll down = -big;

    ll ans = big;

    for(int c1 = 0; c1 < sz(bus); c1++){
        if(bus[c1] != -1){
            if(out[bus[c1]] >= i){
                up = min(up,out[bus[c1]]);
            }
            if(out[bus[c1]] <= i){
                down = max(down,out[bus[c1]]);
            }
        }
    }

    if(up != big){

        vl bus2;
        ll extra = abs(up-i);
        for(int c1 = 0; c1 < sz(bus); c1++){
            if(bus[c1] == -1){
                bus2.push_back(-1);
            }
            else{
                if(out[bus[c1]] == up){
                    bus2.push_back(-1);
                    extra++;
                }
                else{
                    bus2.push_back(bus[c1]);
                }
            }
        }
        ans = min(ans,extra + dp(up,nex,bus2));

    }

    if(down != -big){

        vl bus2;
        ll extra = abs(down-i);
        for(int c1 = 0; c1 < sz(bus); c1++){
            if(bus[c1] == -1){
                bus2.push_back(-1);
            }
            else{
                if(out[bus[c1]] == down){
                    bus2.push_back(-1);
                    extra++;
                }
                else{
                    bus2.push_back(bus[c1]);
                }
            }
        }
        ans = min(ans,extra + dp(down,nex,bus2));

    }

    if(!ful && nex != n){
        if(enter[nex] < up && enter[nex] > down){
            vl bus2;
            for(int c1 = 0; c1 < sz(bus); c1++){
                if(bus[c1] == -1 && !ful){
                    bus2.push_back(nex);
                    ful = 1;
                }
                else{
                    bus2.push_back(bus[c1]);
                }
            }
            ans = min(ans, 1+abs(enter[nex]-i)+dp(enter[nex], nex+1,bus2));
        }
    }
    M[h] = ans;
    return ans;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n;
   // n = 2000;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a >> b;
        //a = rand()%9+1;
        //b = rand()%9+1;
        a--;
        b--;
        enter[c1] = a;
        out[c1] = b;
    }
    vl bus;
    for(int c1 = 0; c1 < 4; c1++)bus.push_back(-1);
    ll ans = dp(0,0,bus);
    cout << ans << "\n";

    return 0;
}