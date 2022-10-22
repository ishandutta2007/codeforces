//#pragma GCC optimize("O3")   //
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    cin >> T;

    rep(c4,0,T){
        cin >> n >> k;
        vl A(n), CS(n+1, 0);
        rep(c1,0,n){
            cin >> A[c1];
            CS[c1+1] = CS[c1]+A[c1];
        }

        if(CS[n] <= k){
            cout << 0 << "\n";
            continue;
        }
        int ans = 0;
        int ans2 = 0;
        rep(c1,0,n){

            if(k < 0)break;
            int L = c1+1;
            int R = n;
            if(CS[n] - CS[c1+1] <= k){
                ans = n-1;
                ans2 = c1+1;
                break;
            }
            while(L < R-1){
                int MID = (L+R)/2;
                if(CS[MID] - CS[c1+1] <= k){
                    L = MID;
                }
                else{
                    R = MID;
                }
            }

            if(L-1 > ans){
                ans = L-1;
                ans2 = c1+1;
            }

            k -= A[c1];
        }
        cout << ans2 << "\n";

    }

    return 0;
}