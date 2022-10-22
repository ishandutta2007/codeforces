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

vector<vi> C(MAXN, vi());

map<ll,ll> DP;

ll PAR[MAXN] = {0};

ll dp(ll i, ll par, ll prev){
    PAR[i] = par;
    ll h = MAXN*2*i + prev;
    if(DP.find(h) != DP.end())return DP[h];

    ll ans1 = 0;
    ll ans2 = 0;

    ll extra = sz(C[i])-2;
    //if(extra == -1)extra++;

    trav(j, C[i]){
        if(j != par){
            ans1 = max(ans1, dp(j, i, 0));
        }
    }
    ans1 += extra;

    if(!prev){
        trav(j, C[i]){
            if(j != par){
                ans2 = max(ans2, dp(j, i, 1));
            }
        }
        ans2++;
    }

    ll ans = max(ans1, ans2);
    DP[h] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n;
    rep(c1,0,n-1){
        cin >> a >> b;
       // a = c1+1;
      //  b = c1+2;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }

    ll ans = dp(0,-1,0);

    rep(i,0,n){

        ll extra = max(0, sz(C[i])-2);
        ll ans1 = 0;
        ll ans2 = 0;
        {
            vi ANS;
            trav(j, C[i]){
                if(j != PAR[i]){
                    ANS.push_back(dp(j,i,0));
                }
            }
            sort(all(ANS));
            reverse(all(ANS));
            if(sz(ANS) >= 2){
                ans1 = extra + ANS[0] + ANS[1];
            }
        }
        {
            vi ANS;
            trav(j, C[i]){
                if(j != PAR[i]){
                    ANS.push_back(dp(j,i,1));
                }
            }
            sort(all(ANS));
            reverse(all(ANS));
            if(sz(ANS) >= 2){
                ans2 = 1 + ANS[0] + ANS[1];
            }
        }
        ans = max(ans, ans1);
        ans = max(ans, ans2);
    }
    cout << ans << "\n";


    return 0;
}