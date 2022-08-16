#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 2e3 + 1;

int n, d;
vi g[N];

int a[N], visited[N];
ll cnt[N];

int cur;

void dfs(int x) {
    visited[x] = 1;
    cnt[x] = 1;

    for (int &i : g[x]) {
        if (visited[i] or a[i] < a[cur] or a[i] > a[cur] + d) continue;
        if (a[i] == a[cur] and i > cur) continue;
        dfs(i);
        cnt[x] = (cnt[x] * (cnt[i] + 1)) % mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> d >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

//    sort(a, a + n);

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        fill(visited, visited + n + 1, 0);
        fill(cnt, cnt + n + 1, 0);
        cur = i;

        dfs(i);
        ans = (ans + cnt[i]) % mod;
    }

    cout << ans << "\n";
    return 0;
}