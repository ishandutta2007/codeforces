#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 200006;

map<ll,ll> M;
vl D;
vl streak;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> k;
        M.clear();
        D.clear();
        streak.clear();
        rep(c1,0,n){
            cin >> a;
            if(M.find(a) == M.end()){
                D.push_back(a);
                M[a] = 0;
                streak.push_back(0);
            }
            M[a]++;
        }
        sort(all(D));
        ll ans = 0;
        ll x = -1;
        ll y = -1;
        rep(c1,0,sz(D)){
            if(c1 > 0 && D[c1-1]+1 == D[c1] && M[D[c1]] >= k && M[D[c1-1]] >= k){
                streak[c1] = streak[c1-1]+1;
            }
            else{
                if(M[D[c1]] >= k)streak[c1] = 1;
            }
            if(streak[c1] > ans){
                ans = streak[c1];
                x = D[c1]-streak[c1]+1;
                y = D[c1];
            }
        }
        if(x == -1){
            cout <<  x << "\n";
        }
        else{
            cout << x << " " << y << "\n";
        }
    }

    return 0;
}