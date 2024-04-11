#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int d[N];
pair<int, int> a[N];
int res[N];
vector<int> ls[N];
vector<pair<int, int>> ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        a[i] = {d[i], i * 2 - 1};
    }
    if (n == 1) {
        cout << 1 << ' ' << 2 << endl;
        return 0;
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        int len = a[i].first;
        int id = a[i].second;
        if (res[i]) {
            len--;
            ls[i].push_back(id);
        } else {
            res[i] = id;
        }
        if (len == 0) {
            ans.push_back({id, id + 1});
            continue;
        }
        int newPos = i + len;
        if (res[newPos]) ls[newPos - 1].push_back(id + 1);
        else res[newPos] = id + 1;
    }
    // for (int i = 1; i <= n * 2; i++) {
    //     cout << "in " << i << ' ' << res[i] << endl;
    //     for (int u : ls[i]) {
    //         cout << u << ' ';
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= n * 2; i++) {
        if (!res[i]) break;
        for (int u : ls[i]) {
            ans.push_back({res[i], u});
        }
        if (i > 1) ans.push_back({res[i - 1], res[i]});
    }
    assert(ans.size() == n * 2 - 1);
    for (auto u : ans) {
        cout << u.first << ' ' << u.second << '\n';
    }
    return 0;
}