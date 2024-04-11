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

const int big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 4000004;

int DP[MAXN] = {0};

int mo;

const int SQRT = 2000;


int f(int x, int y){
    int res = 0;
    rep(c1,1,x+1){
        if(x/c1 == y)res++;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

   // while(1){
   /*
        k = 10;
        rep(c1,1,k){
            cerr <<c1 << ": " <<  f(k, c1) << "  -  " << k / c1 - k / (c1+1) << "\n";
        }
*/
   // }


    cin >> n >> mo;

    int sum = 1;
    DP[1] = 1;

    rep(c1,2,n+1){
        DP[c1] = sum;

        int sqrrt = max(int(sqrt(c1)), 5);

        for(int div = 2; c1/div >= max(sqrrt, 1); div++){
            DP[c1] += DP[c1/div];
            if(DP[c1] >= mo)DP[c1] -= mo;

          //  cerr << c1/div << " dsa\n";

        }
        for(int div = 1; div < min(sqrrt, c1); div++){
            ll num = (c1)/(div) - c1/(div+1);
            DP[c1] += (ll(DP[div]) * num)%mo;
            if(DP[c1] >= mo)DP[c1] -= mo;

          //  cerr << div << "  fds\n";
        }
        sum += DP[c1];
        if(sum >= mo)sum -= mo;

      //  cerr << c1 << ": " << DP[c1] << "  sum: " << sum-DP[c1] << "  -  " << 2*DP[c1]-sum << "\n";
       // cerr << sum-DP[c1] << ",";
    }
    cout << DP[n] << "\n";

    return 0;
}