#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
typedef gp_hash_table<int,int> umap;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);
 
ll random2(){
    return (1ll << 31ll)*eng()+eng();
}
 
ll n,m,k,q,T;
 
const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;
 
const ll MAXN = 300001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll a,b,c,d;
 
    cin >> T;

    rep(c4,0,T){
        cin >> n;
        vi A,B;
        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
        }
        rep(c1,0,n){
            cin >> a;
            B.push_back(a);
        }

        int ans = 0;
        for(int bit = 30; bit >= 0; bit--){
            rep(c2,0,n){
                B[c2] ^= (1 << bit);
            }
            vi A2, B2;
            rep(c2,0,n){
                A2.push_back(A[c2]-A[c2]%(1 << bit));
                B2.push_back(B[c2]-B[c2]%(1 << bit));
            }
            sort(all(A2));
            sort(all(B2));
            bool yes = 1;
            rep(c2,0,n){
                if(A2[c2] != B2[c2])yes = 0;
            }

            if(yes){
                ans += (1 << bit);
            }
            else{
                rep(c1,0,n){
                    if((A[c1]&(1 << bit)) != 0)A[c1] -= (1 << bit);
                    if((B[c1]&(1 << bit)) != 0)B[c1] -= (1 << bit);
                }
            }
        }
        cout << ans << "\n";

    }
 
    return 0;
}