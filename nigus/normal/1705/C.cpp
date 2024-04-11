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

const int MAXN = 400006;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> k >> q;

        vl L,R;
        string s;
        cin >> s;
        rep(c1,0,k){
            cin >> a >> b;
            a--;
            b--;
            L.push_back(a);
            R.push_back(b);
        }
        rep(c1,0,q){
            cin >> a;
            a--;
            ll len = n;
            ll x = -1;
            while(a >= len){
                x++;
                len += R[x]-L[x]+1;
            }
            while(x != -1){
                ll d = R[x]-L[x]+1;
                if(a >= len-d){
                    a = L[x] + (a - (len-d));
                }
                x--;
                len -= d;
            }
            cout << s[a] << "\n";
        }

    }

    return 0;
}