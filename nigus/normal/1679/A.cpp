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


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;
    cin >> T;
    rep(c4,0,T){
        cin >> n;
        if(n<3 || n%2==1){
            cout << "-1\n";
        }
        else{
            ll mi,ma;
            if(n%4 == 2){
                ma = 1 + (n-6)/4;
            }
            else{
                ma = n/4;
            }
            if(n%6 == 0){
                mi = n / 6;
            }
            if(n%6 == 2){
                mi = 2 + (n-8) / 6;
            }
            if(n%6 == 4){
                mi = 1 + (n-4) / 6;
            }
            cout << mi << " " << ma << "\n";
        }
    }

    return 0;
}