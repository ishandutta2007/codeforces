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

const int MAXN = 200006;

ll A[201][201] = {0};

bool inbounds(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> q;
        vl A;
        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
        }
        sort(all(A));
        reverse(all(A));
        vl CS;
        CS.push_back(0);
        rep(c1,0,n){
            CS.push_back(CS[c1]+A[c1]);
        }
        rep(c1,0,q){
            cin >> a;
            int lo = 0;
            int hi = n+1;
            while(lo < hi-1){
                int mid = (lo+hi)/2;
                if(CS[mid] >= a){
                    hi = mid;
                }
                else{
                    lo = mid;
                }
            }

        if(hi == n+1){
            hi = -1;
        }
        cout << hi << "\n";}

    }

    return 0;
}