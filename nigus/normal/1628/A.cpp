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

const int MAXN = 400001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n;
        vi A;

        vi suf_mex;
        vi F(n+1, 0);

        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
        }

        int mex = 0;
        for(int c1 = n-1; c1 >= 0; c1--){
            F[A[c1]]++;
            while(F[mex] > 0){
                mex++;
            }
            suf_mex.push_back(mex);
        }
        reverse(all(suf_mex));

        vi F2(n+1, 0);
        vi B;

        mex = 0;
        int start = 0;
        rep(c1,0,n){
            F2[A[c1]]++;
            while(F2[mex] > 0){
                mex++;
            }
            if(mex == suf_mex[start]){
                B.push_back(suf_mex[start]);
                rep(c2,start,c1+1){
                    F2[A[c2]] = 0;
                }
                start = c1+1;
                mex = 0;
            }
        }

        cout << sz(B) << "\n";
        trav(y, B){
            cout << y << " ";
        }cout << "\n";

    }

    return 0;
}