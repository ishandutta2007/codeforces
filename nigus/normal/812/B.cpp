#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll big = 1000000007ll;
ll big2 = 1000000009ll;

ll n,m,T,k,q;

vector<vector<ll> > C(120, vector<ll>());
ll DP[16][2] = {0};
vector<ll> B;
ll dp(ll i, ll p){
    if(i == n)return -1;
    if(DP[i][p] != -1)return DP[i][p];
    ll ans = m+2+dp(i+1,p^1);
    ll ma = 0;
    if(p == 0){
        for(ll c1 = 1; c1 < m+1; c1++){
            if(C[i][c1] == 1)ma = c1;
        }
    }
    else{
        for(ll c1 = m; c1 > 0; c1--){
            if(C[i][c1] == 1)ma = m-c1+1;
        }
    }
    ll ans2 = 2*ma+1+dp(i+1,p);
    if(i == n-1 || B[i])return ma;
    DP[i][p] = min(ans,ans2);
    return DP[i][p];
}

int main()
{
   //freopen("input.txt","r",stdin);
   //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    for(ll c1 = 0; c1 < 16; c1++){
        DP[c1][0] = -1;
        DP[c1][1] = -1;
    }
    cin >> n >> m;
    for(ll c1 = 0; c1 < n; c1++){
        B.push_back(0);
    }
    ll nolls = 1;
    for(ll c1 = 0; c1 < n; c1++){
        string s;
        cin >> s;
        B[n-c1-1] = nolls;
        for(ll c2 = 0; c2 < m+2; c2++){
            ll now = ll(s[c2])-ll('0');
            if(now)nolls = 0;
            C[n-c1-1].push_back(now);
        }
    }
    cout << dp(0,0) << "\n";
    return 0;
}