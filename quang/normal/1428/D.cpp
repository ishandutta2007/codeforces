#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];
vector<pair<int, int>> res;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int need = 0;
    multiset<int> need2;
    multiset<int> need3;
    int cur = n;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) continue;
        if (a[i] == 1 && !need2.empty()) {
            int u = *need2.begin();
            res.push_back({i, u});
            need2.erase(need2.begin());
            continue;
        }
        if (!need3.empty()) {
            int u = *need3.begin();
            need3.erase(need3.begin());
            res.push_back({i, u});
            res.push_back({i, cur});
            if (a[i] == 2) need2.insert(cur);
            if (a[i] == 3) need3.insert(cur);
            cur--;
            continue;
        }
        res.push_back({i, cur});
        if (a[i] == 2) need2.insert(cur);
        if (a[i] == 3) need3.insert(cur);
        cur--;
    }
    if (!need2.empty() || !need3.empty()) cout << -1 << '\n';
    else {
        cout << res.size() << '\n';
        for (auto u : res) cout << n - u.second + 1 << ' ' << u.first << '\n';
    }
    return 0;
}