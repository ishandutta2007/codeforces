#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 512;
const int maxk = 11;
const int inf = 0x3f3f3f3f;

struct Node {
    int ch[10], val;
    Node() {
        reset(ch, -1);
        val = 0;
    }
} trie[maxn];

int n, k, cnt = 1;
int dp1[maxn][maxk][maxn], dp2[maxn][maxk][maxn][maxk], dep[maxn];

void insert(const string &s, int m) {
    int now = 0;
    for (auto ch : s) {
        int idx = ch - '0';
        if (trie[now].ch[idx] == -1) {
            trie[now].ch[idx] = cnt;
            dep[cnt] = dep[now] + 1;
            cnt++;
        }
        now = trie[now].ch[idx];
    }
    trie[now].val += m;
}

inline void upd(int &a, int b) {
    a = min(a, b);
}

int dfs(int u, int rem, int par) {
    if (dp1[u][rem][par] != -1) return dp1[u][rem][par];
    vector<int> adj;
    dp1[u][rem][par] = inf;
    REP(i, 10) if (trie[u].ch[i] != -1) adj.pb(trie[u].ch[i]);
    if (rem) upd(dp1[u][rem][par], dfs(u, rem - 1, u));
    dp2[u][rem][par][adj.size()] = 0;
    ROF(i, int(adj.size()) - 1, 0) REP(j, rem + 1)
                                       upd(dp2[u][rem][par][i], dfs(adj[i], j, par) + dp2[u][rem - j][par][i + 1]);
    upd(dp1[u][rem][par], dp2[u][rem][par][0] + (dep[u] - dep[par]) * trie[u].val);
    return dp1[u][rem][par];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    trie[0] = Node();
    cin >> n >> k;
    REP(i, n) {
        string s;
        int m;
        cin >> s >> m;
        insert(s, m);
    }
    reset(dp1, -1);
    reset(dp2, inf);
    cout << dfs(0, k, 0);
}