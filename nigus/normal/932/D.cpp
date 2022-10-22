#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
ll n,m,k,T,q;

int BL[400001][20] = {0};
ll BLSUM[400001][20] = {0};
ll PAR[400001] = {0};
ll W[400001] = {0};

ll H[400001] = {0};

ll findparent(ll w, ll p){
   // cout << w << " " << p << "   hg\n";
    if(W[BL[p][19]] < w)return -1;
    if(W[p] >= w)return p;

    for(int c1 = 19; c1 >= 0; c1--){
        if((W[BL[p][c1]] < w)){
            return findparent(w,PAR[BL[p][c1]]);
        }
    }
    return findparent(w,PAR[p]);
}

void setupbl(ll i, ll p){
    if(i == p){
        for(int c1 = 0; c1 < 20; c1++){
            BL[i][c1] = i;
            BLSUM[i][c1] = W[i];
        }
        H[i] = 0;
    }
    else{
        for(int c1 = 0; c1 < 20; c1++){
            if(c1 == 0){
                BL[i][c1] = p;
                BLSUM[i][c1] = W[i];
            }
            else{
                BL[i][c1] = BL[BL[i][c1-1]][c1-1];
                BLSUM[i][c1] = BLSUM[i][c1-1] + BLSUM[BL[i][c1-1]][c1-1];
            }
        }
        H[i] = H[p]+1;
    }
}

ll solve(ll i, ll w){
   //if(i == 3) cout <<i << "   w:"<< w << "   h:" << H[i] << "   W:" << W[i] << "   kk\n";
    if(w < W[i])return 0;
    if(H[i] == 0)return 1;

    for(int c1 = 19; c1 >= 0; c1--){
        if((1 << c1) > H[i])continue;
        if(w >= BLSUM[i][c1]){

            return solve(BL[i][c1] , w-BLSUM[i][c1]) + H[i] - H[BL[i][c1]];
        }
    }
    cerr << "error\n";
    return 0;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> q;
    ll last = 0;
    ll i = 1;
    for(int  c1 = 0; c1 < q; c1++){
        cin >> a >> b >> c;
        b = last^b;
        c = last^c;
       // cout << a << b << c << "   real\n";
        b--;
        if(a == 1){
            ll p = findparent(c,b);
            PAR[i] = p;
            if(p == -1){
                PAR[i] = i;
            }
            W[i] = c;
            setupbl(i,PAR[i]);
            i++;
        }
        else{
            ll ans = solve(b,c);
            last = ans;
            cout << ans << "\n";
        }
    }

    return 0;
}