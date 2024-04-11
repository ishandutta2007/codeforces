#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    
    sort(begin(a), end(a));

    deque<pair<int, int>> seg;

    auto addR = [&](pair<int, int> s) {
        while (!seg.empty() && seg.back().second >= s.first) {
            s.first = min(seg.back().first, s.first);
            s.second = max(seg.back().second, s.second);
            seg.pop_back();
        }
        seg.emplace_back(s);
        return;
    };

    auto addL = [&](pair<int, int> s) {
        while (!seg.empty() && seg.front().first <= s.second) {
            s.first = min(seg.front().first, s.first);
            s.second = max(seg.front().second, s.second);
            seg.pop_front();
        }
        seg.emplace_front(s);
        return;
    };

    vector<int> R(n), num(n);
    seg.clear();

    for (int i = 0; i < n; i++) {
        addR(a[i]);
        num[i] = seg.size();
        R[i] = seg.back().second;
    }

    int ans = 0;
    seg.clear();

    for (int i = n - 1; i >= 0; i--) {
        int tmp = (int) seg.size() + (i > 0 ? num[i - 1] : 0);

        int le = 0, ri = seg.size();
        int RR = (i > 0 ? R[i - 1] : INT_MIN);

        while (le < ri) {
            int mid = (le + ri) / 2;
            if (seg[mid].first <= RR) {
                le = mid + 1;
            } else {
                ri = mid;
            }
        }

        ans = max(ans, tmp - le);
        addL(a[i]);
    }

    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}