#include <bits/stdc++.h>
using namespace std;
using lint = long long;
lint INF = 1e15;

lint X[2005], Y[2005], K[2005];
lint adj[2005][2005];
int p[2005];

int par(int n) {
    return (p[n] == n)? n : p[n] = par(p[n]);
}

void join(int a, int b) {
    a = par(a), b = par(b);
    if (a == b) return;
    p[a] = b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N; cin >> N;
    iota(p, p + N + 1, 0);
    vector<pair<lint, pair<lint, lint>>> E;
    for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            adj[i][j] = INF;
        }
    }
    for (int i = 1; i <= N; i++) {
        cin >> adj[0][i];
        // adj[i][0] = adj[0][i];
        E.push_back({adj[0][i], {0, i}});
    }
    for (int i = 1; i <= N; i++) {
        cin >> K[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            adj[i][j] = (K[i] + K[j]) * (labs(X[i] - X[j]) + labs(Y[i] - Y[j]));
            E.push_back({adj[i][j], {i, j}});
        }
    }
    sort(E.begin(), E.end());
    lint ans = 0;
    vector<pair<int, int>> print;
    set<int> v;
    for (int i = 0; i < E.size(); i++) {
        // cout << "Edges " << E[i].second.first << " " << E[i].second.second << " " << E[i].first << "\n";
        int a = E[i].second.first, b = E[i].second.second;
        a = par(a), b = par(b);
        if (a == b) continue;
        ans += E[i].first;
        p[a] = b;
        if (E[i].second.first == 0 || E[i].second.second == 0) {
            a = E[i].second.first, b = E[i].second.second;
            int c = (a == 0)? b : a;
            v.insert(c);
        } else {
            print.push_back(E[i].second);
        }

    }
    cout << ans << "\n";
    cout << v.size() << '\n';
    for (auto i : v) cout << i << " ";
    cout << "\n";
    cout << print.size() << "\n";
    for (auto i : print) cout << i.first << " " << i.second << "\n";
}