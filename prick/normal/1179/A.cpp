#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

int n;
deque<int> a;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int q;
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ma = *max_element(begin(a), end(a));
    vector<pair<int, int>> ans;
    while (a.front() != ma) {
        int x = a.front(); a.pop_front();
        int y = a.front(); a.pop_front();
        a.push_front(max(x, y));
        a.push_back(min(x, y));
        ans.emplace_back(x, y);
    }
    for (int i = 0; i < q; ++i) {
        int m;
        cin >> m;
        pair<int, int> out;
        --m;
        if (m < sz(ans)) {
            out = ans[m];
        } else {
            out.first = a[0];
            out.second = a[1 + (m - sz(ans)) % (n - 1)];
        }
        cout << out.first << ' ' << out.second << '\n';
    }
}