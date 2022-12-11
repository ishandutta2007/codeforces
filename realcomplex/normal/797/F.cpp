#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = 5005;
const ll inf = (ll)1e18;

ll dp[N][N];
ll cor[N];
ll pref[N];

// dp[i][j] = pf[j] + dp[i-1][k] - pf[k]

ll ab(ll x){
    return max(x,-x);
}

pii hl[N];

ll f(int k, int id){
    return dp[k-1][id] - pref[id];
}

int main(){
    fastIO;
    for(int i = 0 ; i < N; i ++ ) for(int j = 0 ; j < N ; j ++ ) dp[i][j] = inf;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n ; i++ ){
        cin >> cor[i];
    }
    for(int i = 1; i <= m ; i ++ ){
        cin >> hl[i].fi >> hl[i].se;
    }
    sort(cor + 1, cor + 1 + n);
    sort(hl + 1, hl + 1 + m);
    dp[0][0] = 0;
    ll cur;
    for(int i = 1; i <= m; i ++ ){
        for(int j = 1; j <= n; j ++ ) pref[j] = ab(cor[j] - hl[i].fi) + pref[j - 1];
        deque<pii> pf;
        pf.push_back(mp(0, 0));
        for(int j = 1; j <= n; j ++ ){
            cur = dp[i - 1][j] - pref[j];
            while(!pf.empty() && pf.back().fi >= cur){
                pf.pop_back();
            }
            pf.push_back(mp(cur, j));
            while(!pf.empty() && j - pf.front().se > hl[i].se) 
                pf.pop_front();
            dp[i][j] = pref[j] + pf.front().fi;
        }
    }
    cout << (dp[m][n] >= inf ? -1 : dp[m][n]);
    return 0;
}