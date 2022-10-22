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

const int MAXN = 200101;

ll f(ll f1, ll f2){
    if(f1 < 0 || f2 < 0)return big*big;
    ll res = 2*min(f1,f2);
    if(f1 > f2){
        res += 2*(f1-f2)-1;
    }
    else{
        res += 2*(f2-f1);
    }
    return res;
}

ll solve(ll goal, vl &A){
    ll extra = 0;
    ll F[3] = {0};
    ll onepairs = 0;
    rep(c1,0,n){
        F[1] += (goal-A[c1])/3;
        F[2] += (goal-A[c1])/3;
        onepairs += (((goal-A[c1]))/3   +   ((goal-A[c1])%3 == 1)   )/2;
        F[(goal-A[c1])%3]++;
    }

    ll ans = f(F[1], F[2]);

   // cerr << ans <<  "  fds\n";

    rep(c1,-2*n,2*n){
        if(-c1 > onepairs)continue;
        ll temp = f(F[1]+2*ll(c1), F[2]-ll(c1));

        //cerr << goal << "  " << F[1] << "  " << F[2] << ": " << temp << "\n";

        ans = min(ans, temp);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;

    rep(c4,0,T){
        cin >> n;
        vl A;
        ll ma = -121212;
        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
            ma = max(a ,ma);
        }

        ll ans = big*big;

        rep(c1,0,4){
            ans = min(ans, solve(ma+c1, A));
        }
        cout << ans << "\n";

    }

    return 0;
}