#pragma GCC optimize("O3")   //
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

const int MAXN = 200001;

ll a,b,c,d;

ll f(ll x){
    return x*a+a-((x*x+x)/2) * b * d;
}

ll brutt(ll R){
    ll res = -big;
    for(ll x = 0; x <= R; x++){
        res = max(res, f(x));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    cin >> T;

    rep(_,0,T){
        cin >> a >> b >> c >> d;
        /*
        a = random2()%1000000;
        b = random2()%1000;
        c = random2()%1000000;
        d = random2()%1000;
        */
        if(c < d){
            if(a > b*c){
                cout << "-1\n";
            }
            else{
                cout << a << "\n";
            }
            continue;
        }
        ll ans = a;
        ll l = 0;
        ll r = c/d+1;
        while(l < r-1){
            ll mid = (l+r)/2;
            ll F = f(mid);
            if(mid >= 0){
                ans = max(ans, F);
            }
            if(F < f(mid+1)){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        ll start = f(c/d);
        ll extra = c%d;
        k = c/d;
        ll mi = extra * (k+1) * b + (d-extra-1) * k * b;
        ll plu = a - b*k;

        if(plu > mi){
            cout << "-1\n";
        }
        else{
            /*
                if(ans != brutt(c/d)){
                    cerr << "ERROR: " << ans <<"  vs  " << brutt(c/d) << "\n";
                }
            */
            cout << ans << "\n";
        }

    }

    return 0;
}