//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 2e5 + 100;
char mark[maxn];
vector<int> adj[maxn],
    jda[maxn];
int n, m;
int dp[maxn],
    pd[maxn];

void dfs(int u) {
    mark[u] = 1;
    dp[u] = u;
    for (auto v: adj[u]) {
        if (mark[v] == 0) {
            dfs(v);
        }
        else if (mark[v] == 1) {
            cout << -1 << endl;
            exit(0);
        }
        smin(dp[u], dp[v]);
    }
    mark[u] = 2;
}

void sfd(int u) {
    mark[u] = 1;
    pd[u] = u;
    for (auto v: jda[u]) {
        if (mark[v] == 0) {
            sfd(v);
        }
        else if (mark[v] == 1) {
            cout << -1 << endl;
            exit(0);
        }
        smin(pd[u], pd[v]);
    }
    mark[u] = 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int fi, se;
        cin >> fi >> se;
        fi--, se--;
        adj[fi].PB(se);
        jda[se].PB(fi);
    }
    for (int i = 0; i < n; i++)
        if (!mark[i])
            dfs(i);
    memset(mark, false, sizeof mark);
    for (int i = 0; i < n; i++)
        if (!mark[i])
            sfd(i);
    string ans;
    for (int i = 0; i < n; i++) {
        if (dp[i] < i or pd[i] < i)
            ans += 'E';
        else
            ans += 'A';
    }
    cout << count(all(ans), 'A') << '\n';
    cout << ans << '\n';
	return 0;
}