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

const int MAXN = 100001;

const int SQRT = 501;
vl A;

ll BIGGEST[MAXN][SQRT] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    int a,b,c,d,e;

    cin >> T;

    rep(c4,0,T){
        cin >> n;
        A.clear();
        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
        }

        reverse(all(A));
        //vector<vector<pll> > VP(SQRT, vector<pll>());



        rep(c1,0,n){
            BIGGEST[c1][0] = big;
            rep(c2,1,SQRT){
                BIGGEST[c1][c2] = 0;
            }
        }

        rep(c1,0,n){
            ll sum = 0;
            rep(c2,1,SQRT){

                BIGGEST[c1][c2] = 0;
                if(c1 > 0)BIGGEST[c1][c2] = BIGGEST[c1-1][c2];

                int before = c1 - c2 + 1;
                if(before >= 0 && c1+c2-1 < n){
                    sum += A[c1+c2-1];
                    if(before >= 0){
                        if(BIGGEST[before][c2-1] > sum && sum > BIGGEST[c1][c2]){
                            BIGGEST[c1][c2] = sum;
                        }
                    }
                }
            }

        }

        ll ans = 0;
        rep(c1,1,SQRT){
            if(BIGGEST[n-1][c1] != 0)ans = c1;
        }
        cout << ans << "\n";

    }


    return 0;
}