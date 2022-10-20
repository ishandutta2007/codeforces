#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n, m;
int h[N], s[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int cur = 0;
    vector<int> vals;
    vals.push_back(0);
    vals.push_back(n);
    for (int i = 1; i <= m; i++) {
        cin >> h[i];
        cur = (cur + h[i]) % n;
        if (i < m) vals.push_back(cur);
    }
    sort(vals.begin(), vals.end());
    for (int i = 1; i <= m; i++) {
        s[i] = vals[i] - vals[i - 1];
    }
    vector<int> res;
    int now = 1;
    for (int i = 1; i <= m; i++) {
        while (h[i] > 0) {
            res.push_back(i);
            h[i] -= s[now];
            now = (now == m ? 1 : now + 1);
        }
    }
    while (res.size() % m) res.push_back(1);
    cout << (res.size() - 1) / m + 1 << '\n';
    for (int i = 1; i <= m; i++) {
        cout << s[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
        if ((i + 1) % m == 0) cout << '\n';
    }
    return 0;
}