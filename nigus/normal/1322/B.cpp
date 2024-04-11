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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 1000001;

const int MAXA = 10000001;

int F[MAXA] = {0};
vl A;

ll FF[27] = {0};
ll stupid(){
    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = c1+1; c2 < n; c2++){
            for(int c3 = 0; c3 < 27; c3++){
                ll sum = A[c1] + A[c2];
                if((sum & (1 << c3)) != 0)FF[c3]++;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    rep(c1,0,n){
        cin >> a;
       // a = random2()%10000000;
        A.push_back(a);
    }

    ll ans = 0;

   // stupid();

    for(int c1 = 25; c1 >= 0; c1--){
        ll sum = 0;


        ll ma = min(MAXA-1, (1 << (c1+2)));
        for(int c2 = 0; c2 <= ma; c2++){
            F[c2] = 0;
        }
        for(int c2 = 0; c2 < n; c2++){
            F[A[c2]]++;
        }
        for(int c2 = 1; c2 <= ma; c2++){
            F[c2] += F[c2-1];
        }
       // ll sum = 0;
        for(int c2 = 0; c2 < n; c2++){
            ll least = (1 << c1) - A[c2];
           // cerr << c1 << " " << least << " " << A[c2] << "\n";
            if(least > ma)continue;
            ll temp = 0;
            if(least <= 0){
                temp = n;
            }
            else{
                temp = n - F[least-1];
            }

            ll i2 = (1 << (c1+1)) - A[c2];
            ll i3 = (1 << (c1+1)) + (1 << c1) - A[c2];
            i2 = min(ma, i2);
            i3 = min(ma, i3);
           // cerr << F[i3-1] - F[i2-1] << "\n";
            temp -= F[i3-1] - F[i2-1];
           // cerr << "exp: " << c1 << ", A[c2]: " << A[c2] << "  temp: " << temp << "\n";

            if(((A[c2] + A[c2]) & (1 << c1)) != 0)temp--;

            sum += temp;
        }
        sum /= 2;

       // cerr << sum << " " << FF[c1] << "\n";

       // if(sum != FF[c1])cerr << "NOOOOOO\n";

        if(sum%2 == 1){
            ans += (1 << c1);
        }

        rep(c2,0,n){
            if((A[c2] & (1 << c1)) != 0){
                A[c2] -= (1 << c1);
            }
        }


    }

    cout << ans << "\n";

    return 0;
}