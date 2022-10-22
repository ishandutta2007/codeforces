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

const int MAXN = 300001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> k;
        vl A;
        ll sum = 0;
        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
            sum += a;
        }
        sort(all(A));
        ll ans = max(0ll, sum-k);

        ll sum2 = 0;
        for(int c1 = n-1; c1 > 0; c1--){
            sum2 += A[c1];
            ll L = sum-sum2;
            ll i = n-c1;

            ll t = max(0ll, (L-k+A[0]*i+i) / (i+1));
            ans = min(ans, t + i);

        }
        cout << ans << "\n";

    }

    return 0;
}