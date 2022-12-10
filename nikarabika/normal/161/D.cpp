#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 5e4 + 5;
const int maxk = 5e2 + 5;
int n, k;
ll ans = 0;
bool mark[2][maxn];
pie dp[maxn][maxk];
vector <int> v[maxn];

void dfs_down(int x){
    mark[0][x] = true;
    dp[x][0].p1 = 1;
    rep(i, v[x].size()){
        int ch = v[x][i];
        if(!mark[0][ch]){
            dfs_down(ch);
            reu(j, 1, k)
                dp[x][j].p1 += dp[ch][j - 1].p1;
        }
    }
}

void dfs_up(int x){
    mark[1][x] = true;
    rep(i, v[x].size()){
        int ch = v[x][i];
        if(!mark[1][ch]){
            dp[ch][0].p2 = 1;
            dp[ch][1].p2 += 1;
            reu(j, 2, k)
                dp[ch][j].p2 += dp[x][j - 1].p2 + dp[x][j - 1].p1 - dp[ch][j - 2].p1;
            dfs_up(ch);
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
    cin >> n >> k;
    rer(i, 1, n){
        int fi, se;
        cin >> fi >> se;
        v[fi].pb(se);
        v[se].pb(fi);
    }
    dfs_down(1);
    dp[1][0].p2 = 1;
    dfs_up(1);
    reu(i, 1, n)
        ans += dp[i][k].p1 + dp[i][k].p2;
    cout << ans / 2 << endl;
	return 0;
}