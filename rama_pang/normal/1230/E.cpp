#include <bits/stdc++.h>
using namespace std;
using lint = long long;
lint MOD = 1e9 + 7;

lint gcd(lint a, lint b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return gcd(b, a % b);
}

int N;
vector<int> G[100005];
lint B[100005];
lint ans = 0;

map<lint, lint> mp[100005];

void dfs(int n = 0, int p = -1) {
    if (p != -1) for (auto i : mp[p]) {
        mp[n][gcd(B[n], i.first)] += i.second;
    }
    mp[n][B[n]]++;

    for (auto i : mp[n]) {
        ans += (i.first * i.second) % MOD;
        ans %= MOD;
    }

    for (auto i : G[n]) if (i != p) {
        dfs(i, n);
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs();

    cout << ans << "\n";

}