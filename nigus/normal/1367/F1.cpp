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

const int MAXN = 300001;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;

    rep(c4,0,T){
        cin >> n;
        vi A,A2;
        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
            A2.push_back(a);
        }
        sort(all(A2));
        map<ll,ll> M;
        d = 0;
        vl best;
        vl bestest;
        vl seen;
        vl tot;
        trav(i, A2){
            if(M.find(i) == M.end()){
                M[i] = d;
                best.push_back(0);
                bestest.push_back(0);
                seen.push_back(0);
                tot.push_back(0);
                d++;
            }
            tot[M[i]]++;
        }
        ll ans = 0;
        rep(c1,0,n){
            ll i = M[A[c1]];
            seen[i]++;

            if(i == 0){
                best[i]++;
            }
            else{
                if(seen[i-1] == tot[i-1]){
                    best[i] = 1 + max(best[i], bestest[i-1] + seen[i-1]);
                }
                else{
                    best[i] = 1 + max(best[i], seen[i-1]);
                }
            }

            if(seen[i] == 1){
                bestest[i] = best[i]-1;
            }

            //cerr << c1+1 << ": " << best[i] << "\n";
            ans = max(ans, best[i]);
        }

        /*
        rep(c1,0,n){
            cerr << A[c1] << " ";
        }cerr << "\n";
        rep(c1,0,n){
            cerr << A2[c1] << " ";
        }cerr << "\n";
*/
        cout << n-ans << "\n";
    }


    return 0;
}