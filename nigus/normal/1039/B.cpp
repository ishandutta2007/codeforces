#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<double,double> pdd;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,q;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> D(0, 1000000000);

ll random(ll r){
    return D(eng)%r;
}

ll query(ll l, ll r){
    cout << l+1 << " " << r+1 << "\n";
    fflush(stdout);
    string res;
    cin >> res;
    if(res[0] == 'B'){
        return -1;
    }
    if(res[0] == 'Y'){
        return 1;
    }
    return 0;
}

ll random_guess(ll l, ll r){
    ll ra = random(r-l+1);
    return query(l+ra,l+ra);
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;


    cin >> n >> k;

    ll L = 0;
    ll R = n-1;

    while(1){

        if(R-L+1 < 50){
            ll res = random_guess(L,R);
            if(res == -1 || res == 1){
                break;
            }
            L -= k;
            R += k;
            L = max(0ll,L);
            R = min(n-1,R);
        }
        else{
            ll res = query(L,L+(R-L)/2);
            if(res == -1){
                return 0;
            }
            if(res == 0){
                L = L+(R-L)/2 + 1 - k;
                R = R+k;
            }
            else{
                R = L+(R-L)/2 + k;
                L = L-k;

            }
            L = max(0ll,L);
            R = min(n-1,R);
        }


    }


    return 0;
}