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

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

// b * (a + 1)
// (k - x + 1) * (x + 1)

const int MAXC = 1000001;

ll ANS[MAXC] = {0};

ll f(ll k, ll x){
    return (k - x + 1) * (x + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    cin >> T;
    rep(c1,0,MAXC){
        a = f(c1,c1/2);
        ANS[c1] = max(a, max(f(c1,c1/2-1), f(c1,c1/2+1)));
    }
    rep(c4,0,T){
        cin >> n;
        if(n == 1){
            cout << 0 << "\n";
            continue;
        }
        int L = 0;
        int R = MAXC;
        while(L < R-1){
            int MID = (L+R)/2;
            if(ANS[MID] < n){
                L = MID;
            }
            else{
                R = MID;
            }
        }
        cout << R << "\n";
    }

    return 0;
}