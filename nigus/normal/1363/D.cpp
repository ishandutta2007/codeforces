#pragma GCC optimize("O3")   //
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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 1001;



int main() {
  //  ios_base::sync_with_stdio(0);
   // cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;

    rep(_,0,T){
        cin >> n >> k;
        vector<vi> I(k, vi());
        int SS[1001] = {0};
        rep(c1,0,n){
            SS[c1] = -1;
        }
        rep(c1,0,k){
            cin >> b;
            rep(c2,0,b){
                cin >> a;
                a--;
                SS[a] = c1;
                I[c1].push_back(a);
            }
        }
        cout << "? " << n << " ";
        rep(c1,0,n){
            cout << c1+1 << " ";
        }cout << "\n";
        fflush(stdout);

        cin >> a;
        assert(a != -1);
        ll ma = a;

        ll ix = 0;
        rep(c1,0,10){
            vi ind;
            rep(c2,0,n){
                if((c2&((1 << c1) + ix)) == ((1 << c1) + ix)){
                    ind.push_back(c2);
                }
            }
            if(sz(ind) > 0){
                cout <<"? " << sz(ind) << " ";
                trav(y, ind){
                    cout << y+1 << " ";
                }cout << "\n";
                fflush(stdout);

                cin >> a;
                assert(a != -1);
                if(a == ma){
                    ix += (1 << c1);
                }
            }
        }

      //  cerr << "ix " << ix << "\n";

        if(SS[ix] == -1){
            cout << "! ";
            rep(c1,0,k){
                cout << ma << " ";
            }cout << "\n";
            fflush(stdout);
        }
        else{
            vi ind;
            rep(c1,0,n){
                if(SS[c1] != SS[ix]){
                    ind.push_back(c1);
                }
            }
            cout << "? " << sz(ind) << " ";
            trav(y, ind){
                cout << y+1 << " ";
            }cout << "\n";
            fflush(stdout);

            cin >> a;
            assert(a != -1);

            cout << "! ";
            rep(c1,0,k){
                if(c1 == SS[ix]){
                    cout << a << " ";
                }
                else{
                    cout << ma << " ";
                }
            }
            cout << "\n";
            fflush(stdout);



        }
        string stupid;
        cin >> stupid; // why

    }

    return 0;
}