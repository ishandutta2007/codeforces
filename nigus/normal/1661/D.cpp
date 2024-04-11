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

const int MAXN = 300101;

vl B;

ll added[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    ll n,k;
    cin >> n >> k;
    rep(c1,0,n){
        cin >> a;
        B.push_back(a);
    }
    ll fri = 0;
    ll pro = 0;

    ll ans = 0;

    for(int c1 = n-1; c1 >= 0; c1--){
        fri -= pro;
        if(c1+k < n){
            pro -= added[c1+k];
        }

        ll x = B[c1] - fri;

        ll k2 = min(ll(c1)+1, k);

        if(x > 0){
            added[c1] = (x+k2-1)/k2;
            fri += k2*added[c1];
            pro += added[c1];
            ans += added[c1];
        }
    }
    cout << ans << "\n";

    return 0;
}