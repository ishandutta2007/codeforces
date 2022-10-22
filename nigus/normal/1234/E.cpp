#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
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
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return (1000000000 * ll(DD(eng)) + DD(eng))%r;
}

ll n,m,T,k,q;
const ll big = 1000000007;
const ll MAXN = 300001;

vector<vi> C(MAXN, vi());
vl A;

int main() {
   // ios_base::sync_with_stdio(0);
    //cin.tie(0);

    ll a,b,c;

    cin >> n >> m;

    ll actual = 0;
    rep(c1,0,m){
        cin >> a;
        A.push_back(a-1);
        if(c1 > 0){
            actual += abs(a-1-A[c1-1]);
        }
        C[a-1].push_back(c1);
    }

    ll atoc = 0;

    rep(c1,0,n){

        ll ans = actual - atoc;
        //cerr << atoc << "\n";

        trav(y, C[c1]){
            a = y-1;
            if(a >= 0){
                if(A[a] > c1){
                    ans += A[a] - (abs(A[a] - c1));
                    atoc++;
                }
                if(A[a] < c1){
                    ans += A[a] + 1 - (abs(A[a] - c1) - 1);
                    atoc--;
                }
            }
            a = y+1;
            if(a < m){
               // cerr << a << " " << A[a] << " " << c1 << "\n";
                if(A[a] > c1){
                    ans += A[a] - (abs(A[a] - c1));
                    atoc++;
                }
                if(A[a] < c1){
                    ans += A[a] + 1 - (abs(A[a] - c1) - 1);
                    atoc--;
                }
            }
        }
        cout << ans << " ";

    }


    return 0;
}