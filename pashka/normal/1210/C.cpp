#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka
vector<vector<int>> g;
vector<long> w;

long gcd(long a, long b) {
    while (b > 0) {
        long c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long res = 0;
long MOD = 1000000007;

void dfs(int x, int p, vector<pair<long, int>> &q) {
    vector<pair<long, int>> qq;
    for (auto s : q) {
        long c = gcd(s.first, w[x]);
        if (qq.size() > 0 && qq.back().first == c) {
            qq.back().second += s.second;
        } else {
            qq.push_back({c, s.second});
        }
    }
    {
        long c = w[x];
        if (qq.size() > 0 && qq.back().first == c) {
            qq.back().second += 1;
        } else {
            qq.push_back({c, 1});
        }
    }
    for (auto s : qq) {
        res += s.first * s.second;
        res %= MOD;
    }
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if (y != p) {
            dfs(y, x, qq);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;

    w.resize(n);
    for (int i = 0; i < n; i++) cin >> w[i];

    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<pair<long, int>> q;
    dfs(0, -1, q);

    cout << res << "\n";

    return 0;
}