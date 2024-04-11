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

vector<vector<pll> > D(501, vector<pll>());

bool DP[501][501] = {0};
vector<pll> now;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> k;
    vl A,B;
    ll sum = 0;
    ll ak = 0;
    ll bk = 0;

    rep(c1,0,n){
        cin >> a >> b;
        sum += a;
        sum += b;

        ak += a%k;
        bk += b%k;
        ll r = (a+b)%k;

        rep(c2,0,k){
            ll a2 = c2;
            ll b2 = (r-c2+k)%k;
            if(a2 <= a && b2 <= b){
                D[c1].push_back({(a - a2)%k, (b - b2)%k});
            }
        }

        A.push_back(a);
        B.push_back(b);
    }

    ak%=k;
    bk%=k;

    ll ans = sum/k-1;
    if(ak+bk < k){
        cout << ans+1 << "\n";
        return 0;
    }

    rep(c1,0,n){
        trav(p, D[c1]){
            ll a2 = (ak-p.first+k)%k;
            ll b2 = (bk-p.second+k)%k;
            if(a2+b2 < k){
                ans = sum/k;
                cout << ans << "\n";
                return 0;
            }
        }
    }


    DP[0][0] = 1;
    now.push_back({0,0});

    rep(c1,0,n){
        vector<pll> now2;
        trav(p1, D[c1]){
            trav(p2, now){
                a = p1.first + p2.first;
                b = p1.second + p2.second;
                if(a>=k)a-=k;
                if(b>=k)b-=k;
                if(!DP[a][b]){
                    DP[a][b] = 1;
                    now2.push_back({a,b});
                    ll a2 = (ak-a+k)%k;
                    ll b2 = (bk-b+k)%k;
                    if(a2+b2 < k){
                        cout << sum/k << "\n";
                        return 0;
                    }
                }
            }
        }
        trav(p, now2){
            now.push_back(p);
        }
    }


    cout << ans << "\n";

    return 0;
}