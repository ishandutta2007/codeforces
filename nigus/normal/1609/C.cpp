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

const int MAXS = 1000001;

ll e;

bool prime[MAXS] = {0};
bool mark[MAXS] = {0};



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    rep(c1,2,MAXS){
        if(!mark[c1]){
            prime[c1] = 1;
            for(int c2 = 2*c1; c2 < MAXS; c2 += c1){
                mark[c2] = 1;
            }
        }
    }
    cin >> T;
    rep(c4,0,T){
        cin >> n >> e;
        vector<vi> C(e, vi());
        rep(c1,0,n){
            cin >> a;
            C[c1%e].push_back(a);
        }
        ll ans = 0;
        rep(c1,0,e){
            ll n2 = sz(C[c1]);
            int last = n2;
            int lastp = n2;
            for(int c2 = n2-1; c2 >= 0; c2--){
                if(C[c1][c2] != 1 && !prime[C[c1][c2]]){
                    last = c2;
                }
                if(C[c1][c2] == 1){
                    ans += max(0,last-lastp);
                }
                if(prime[C[c1][c2]]){
                    last = min(last, lastp);
                    lastp = c2;
                   // cerr << last << " " << c2 << "  hr\n";
                    ans += last-c2-1;
                }
            }
          //  cerr << ans << "  hej\n";
        }
        cout << ans << "\n";
    }

    return 0;
}