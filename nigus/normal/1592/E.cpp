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

vi A;

int F[2*MAXN] = {0};
int CC[2*MAXN] = {0};
int cc = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n;

    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
    }

    int ans = 0;

    rep(c4,0,21){
        int prev = -1;

        int xo = 0;

        rep(c1,0,n){
            if(A[c1]%2 != prev){
                cc++;
            }
            xo ^= A[c1];

            if(CC[xo] == cc && A[c1]%2 == 1){
            //    if(c4 == 0)cerr << c1+1 << " gh\n";
                int d = c1 - F[xo]+1;
                ans = max(ans, d);
            }

            if(CC[xo^A[c1]] != cc){
                CC[xo^A[c1]] = cc;
                F[xo^A[c1]] = c1;
            }

            prev = A[c1]%2;
        }

       // cerr << ans << "  fd\n";

        rep(c1,0,n){
            A[c1] /= 2;
        }
    }

    cout << ans << "\n";

    return 0;
}