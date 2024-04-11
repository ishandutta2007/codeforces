#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, m;
int a[N][N];

vector<int> get(int u) {
    vector<pair<int, int>> ls;
    for (int i = 1; i <= m; i++) {
        ls.push_back({a[i][u] - a[i][n], i});
    }
    sort(ls.begin(), ls.end());
    reverse(ls.begin(), ls.end());
    int cur = 0;
    int sum = 0;
    while (cur < ls.size() && sum + ls[cur].first >= 0) {
        sum += ls[cur].first;
        cur++;
    }
    vector<int> res;
    for (int i = cur; i < ls.size(); i++) res.push_back(ls[i].second);
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
    vector<int> res;
    for (int i = 1; i <= m; i++) {
        res.push_back(i);
    }
    for (int i = 1; i < n; i++) {
        vector<int> now = get(i);
        if (now.size() < res.size()) res = now;
    }
    cout << res.size() << '\n';
    for (int u : res) {
        cout << u << ' ';
    }
    cout << '\n';
    return 0;
}