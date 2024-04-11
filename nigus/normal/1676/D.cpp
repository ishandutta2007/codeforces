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

ll A[201][201] = {0};

bool inbounds(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> m;

        vl SUM1(n+m+1, 0);
        vl SUM2(n+m+1, 0);

        rep(c1,0,n){
            rep(c2,0,m){
                cin >> a;
                A[c1][c2] = a;
                SUM1[c1+c2] += a;
                SUM2[c1-c2+m] += a;
            }
        }
        ll ans = -big;

        rep(c1,0,n){
            rep(c2,0,m){
                a = SUM1[c1+c2] + SUM2[c1-c2+m] - A[c1][c2];
                ans = max(ans, a);
            }
        }
        cout << ans << "\n";

    }

    return 0;
}