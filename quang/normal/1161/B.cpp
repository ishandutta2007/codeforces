#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
vector<int> ls[N];
int t[N * 2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (u > v) swap(u, v);
        if (v - u == u + n - v) {
            ls[v - u].push_back(u);
            ls[v - u].push_back(v);
        } else if (v - u < u + n - v) {
            ls[v - u].push_back(u);
        } else {
            ls[u + n - v].push_back(v);
        }
    }
    long long res = 1;
    for (int i = 1; i <= n; i++) {
        if (ls[i].empty()) continue;
        if (ls[i].size() == 1) {
            cout << "No" << endl;
            return 0;
        }
        sort(ls[i].begin(), ls[i].end());
        vector<int> val = {0};
        for (int j = 0; j + 1 < ls[i].size(); j++) {
            val.push_back(ls[i][j + 1] - ls[i][j]);
        }
        val.push_back(ls[i][0] + n - ls[i].back());

        // cout << i << endl;
        // for (int u : val) cout << u << ' ';
        //     cout << endl;
        int cur = 0;
        for (int j = 2; j < val.size(); j++) {
            while (cur && val[j] != val[cur + 1]) cur = t[cur];
            cur += val[j] == val[cur + 1];
            t[j] = cur;
        }   
        if (cur == 0) {
            cout << "No" << endl;
            return 0;
        }
        int bar = val.size() - 1 - t[val.size() - 1];
        // cout << bar << endl;
        if ((val.size() - 1) % bar)  {
            cout << "No" << endl;
            return 0;
        }
        int foo = 0;

        for (int j = 1; j <= bar; j++) foo += val[j];

        // cout << i << ' ' << foo << endl;
        if (n % foo) {
            cout << "No" << endl;
            return 0;
        }
        res = 1ll * res * foo / __gcd(res, 1ll * foo);
        if (res >= n) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}