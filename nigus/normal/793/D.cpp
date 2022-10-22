#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,q,T,k;


ll DP1[81][81][81] = {0};
ll DP2[81][81][81] = {0};

vector<vector<ll> > C(81 , vector<ll>());
vector<vector<ll> > CW(81 , vector<ll>());

ll dp2(ll i, ll k2, ll cap);

ll dp1(ll i, ll k2, ll cap){
    if(k2 == 1)return 0;
    ll ans = big*big;

    if(DP1[i][k2][cap] != -1)return DP1[i][k2][cap];
    for(ll c1 = 0; c1 < C[i].size(); c1++){
        ll a = C[i][c1];
        if(a > i && a <= cap){
            ans = min(ans , CW[i][c1] + dp1(a,k2-1,cap));
            ans = min(ans , CW[i][c1] + dp2(a,k2-1,i+1));
        }
    }

    //cout << i << " " << k2 <<" - " << ans <<  "\n";
    DP1[i][k2][cap] = ans;
    return ans;
}

ll dp2(ll i, ll k2, ll cap){
    if(k2 == 1)return 0;
    ll ans = big*big;
    if(DP2[i][k2][cap] != -1)return DP2[i][k2][cap];
    for(ll c1 = 0; c1 < C[i].size(); c1++){
        ll a = C[i][c1];
        if(a < i && a >= cap){
            ans = min(ans , CW[i][c1] + dp2(a,k2-1,cap));
            ans = min(ans , CW[i][c1] + dp1(a,k2-1,i-1));
        }
    }

    DP2[i][k2][cap] = ans;
    return ans;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n >> k;
    cin >> m;
    for(ll c1 = 0; c1 < m; c1++){
        cin >> a >> b >> c;
        a--;
        b--;
        C[a].push_back(b);
        CW[a].push_back(c);
    }

    for(ll c1 = 0; c1 < 81; c1++){
        for(ll c2 = 0; c2 < 81; c2++){
            for(ll c3 = 0; c3 < 81; c3++){
                DP1[c1][c2][c3] = -1;
                DP2[c1][c2][c3] = -1;
            }
        }
    }

    ll ans = big*big;

    for(ll c1 = 0; c1 < n; c1++){
        ans = min(ans , dp1(c1,k,n-1));
        ans = min(ans , dp2(c1,k,0));
    }

    if(ans == big*big){
        cout << -1 << "\n";
    }
    else{
        cout << ans << "\n";
    }

    return 0;
}