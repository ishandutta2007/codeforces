#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 300001;

vl A;

ll sum = 0;

vl P;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;

    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
        sum += a;
    }
    if(sum <= 1){
        cout << "-1\n";
        return 0;
    }

    ll sum2 = sum;
    for(ll p = 2; p*p <= sum; p++){
        if(sum2%p == 0){
            while(sum2%p == 0){
                sum2 /= p;
            }
            P.push_back(p);
        }
    }
    if(sum2 != 1){
        P.push_back(sum2);
    }

    ll ans = big*big;

    trav(p, P){
        ll mid = p/2;
        ll curr = 0;
        ll temp = 0;
        rep(c1,0,n){
            if(A[c1] == 1){
                if(curr == p){
                    curr = 0;
                }
                if(curr < mid){
                    temp += n-c1;
                }
                if(curr > mid){
                    temp += c1;
                }
                if(curr == mid){
                    temp -= (n-c1) * mid;
                    temp -= ll(c1) * (p-mid-1);
                }
                curr++;
            }
        }
      //  cerr << "temp: " << temp << "\n";
        ans = min(ans, temp);
    }

    cout << ans << "\n";

    return 0;
}