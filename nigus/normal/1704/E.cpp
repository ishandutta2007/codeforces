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

const ll MAXN = 1006;

vector<vi> C(MAXN, vi());

int deg2[MAXN] = {0};
vl A;
vi TS;

ll ans = 0;

bool done = 0;

ll DP[MAXN] = {0};

void simulate(){
    ll sum = 0;
    for(int c1 = n-1; c1 >= 0; c1--){
        int i = TS[c1];
        sum += A[i];
        if(A[i] > 0){
            A[i]--;
            trav(y, C[i]){
                A[y]++;
            }
        }
    }
    if(sum == 0){
        done = 1;
        return;
    }
    ans++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll a,b,c,d;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> m;
        done = 0;
        ans = 0;
        A.clear();
        TS.clear();
        rep(c1,0,n){
            C[c1].clear();
        }
        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
            deg2[c1] = 0;
        }
        rep(c1,0,m){
            cin >> a >> b;
            a--;
            b--;
            C[a].push_back(b);
            deg2[b]++;
        }
        vi H;
        rep(c1,0,n){
            if(deg2[c1] == 0){
                H.push_back(c1);
            }
        }
        while(sz(H) > 0){
            a = H.back();
            H.pop_back();
            TS.push_back(a);
            trav(y, C[a]){
                deg2[y]--;
                if(deg2[y] == 0){
                    H.push_back(y);
                }
            }
        }
        rep(c1,0,n+3){
            simulate();
        }
        if(done){
            cout << ans << "\n";
            continue;
        }
        
        for(int c1 = n-1; c1 >= 0; c1--){
            int i = TS[c1];
            if(c1 == n-1){
                DP[i] = 1;
            }
            else{
                ll res = 0;
                trav(y, C[i]){
                    res += DP[y];
                    if(res >= mod)res -= mod;
                }
                DP[i] = res;
            }
            ans += A[i]*DP[i];
            ans %= mod;
        }
        cout << ans << "\n";

        
    }

    return 0;
}