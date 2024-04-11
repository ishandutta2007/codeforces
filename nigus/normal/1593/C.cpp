#pragma GCC optimize("O3")
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

const ll MAXN = 1000004;

vi X;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;

    rep(c4,0,T){
        cin >> m >> n;
        X.clear();
        rep(c1,0,n){
            cin >> a;
            X.push_back(a);
        }
        sort(all(X));

        int L = 1;
        int R = n+1;
        while(L < R-1){
            int MID = (L+R)/2;
            ll t = 0;
            bool tmp = 1;
            for(int c1 = n-MID; c1 < n; c1++){
              //  cerr << MID << ": " << t << "  gf\n";
                if(t >= X[c1]){
                    tmp = 0;
                    break;
                }
                t += m-X[c1];
            }
            if(tmp){
                L = MID;
            }
            else{
                R = MID;
            }

        }
        cout << L << "\n";

    }


    return 0;
}