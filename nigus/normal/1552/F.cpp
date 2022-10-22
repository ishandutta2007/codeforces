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

const int MAXN = 300006;

ll DP[MAXN] = {0};
ll DPC[MAXN] = {0};

vi A;
vl X,Y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n;
    rep(c1,0,n){
        cin >> a >> b >> c;
        A.push_back(c);
        X.push_back(a);
        Y.push_back(b);
    }
    ll ans = 0;
    ll prev = 0;
    rep(c1,0,n){
        int lo = -1;
        int hi = c1;
        while(lo < hi-1){
            int mid = (lo+hi)/2;
            if(X[mid] > Y[c1]){
                hi = mid;
            }
            else{
                lo = mid;
            }
        }
        if(hi == c1){
            DP[c1] = X[c1]-Y[c1];
        }
        else{
            DP[c1] = (DPC[c1] - DPC[hi] + X[c1] - Y[c1] + 4*mod)%mod;
        }
        DPC[c1+1] = (DPC[c1]+DP[c1])%mod;

        if(A[c1] == 1){
            ans += X[c1]-prev;
            ans += DP[c1];
            ans %= mod;
            prev = X[c1];
        }
    }

    ans += X[n-1]+1-prev;

    ans %= mod;

    cout << ans << "\n";

    return 0;
}