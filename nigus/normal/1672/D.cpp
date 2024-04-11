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

const int MAXN = 500006;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n;
        vi A,B;
        vector<vi> C(n, vi());
        vi CI;
        vi F;
        rep(c1,0,n){
            cin >> a;
            a--;
            A.push_back(a);
            CI.push_back(sz(C[a]));
            C[a].push_back(c1);
            F.push_back(1);
        }
        rep(c1,0,n){
            cin >> a;
            a--;
            B.push_back(a);
        }
        bool yes = 1;
        int r = 0;
        rep(c1,0,n){
            while(r < n && A[r] != B[c1]){

                if(CI[r] == sz(C[A[r]])-1){
                    //cerr << c1+1 << "    " << r+1 << "\n";
                    yes = 0;
                    r = n;
                    break;
                }

                F[   C[A[r]][CI[r]+1]    ] += F[r];
                r++;
            }
            if(r >= n){
                yes = 0;
                break;
            }
          //  cerr << c1+1 << " " << r+1 << "  F[r] " << F[r] << "\n";
            F[r]--;
            if(F[r] == 0)r++;
        }
        if(yes){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}