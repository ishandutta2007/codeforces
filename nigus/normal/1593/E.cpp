#pragma GCC optimize("O3")
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

const ll MAXN = 1000004;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;

    rep(c4,0,T){
        cin >> n >> k;
        vector<vi> C(n, vi());
        vi deg(n, 0);
        rep(c1,0,n-1){
            cin >> a >> b;
            a--;
            b--;
            C[a].push_back(b);
            C[b].push_back(a);
            deg[a]++;
            deg[b]++;
        }
        vi leaves;
        vi gone(n, 0);

        rep(c1,0,n){
            if(sz(C[c1]) <= 1){
                leaves.push_back(c1);
                gone[c1] = 1;
            }
        }

        int ans = n;
        rep(_,0,k){
            vi new_leaves;
            trav(y, leaves){
                ans--;
                gone[y] = 2;
                trav(yy, C[y]){
                    deg[yy]--;
                    if(gone[yy] == 0 && deg[yy] <= 1){
                        gone[yy] = 1;
                        new_leaves.push_back(yy);
                    }
                }
            }
            leaves = new_leaves;
        }
        cout << ans << "\n";

    }


    return 0;
}