#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<pair<pair<int, int>, int>> a(n);
    vector<int> events(200005);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first.first >> a[i].first.second;
        events[a[i].first.first]++;
        events[a[i].first.second + 1]--;
        a[i].second = i + 1;
    }
    sort(begin(a), end(a));
    int active = 0;
    vector<int> bad;
    priority_queue<pair<int, int>> pq;
    vector<int> ans;

    for (int i = 1, ptr = 0; i < 200005; i++) {
        events[i] += events[i - 1];
        while (ptr < n && i == a[ptr].first.first) {
            pq.emplace(a[ptr].first.second, a[ptr].second);
            ptr++;
        }
        while (!pq.empty() && pq.top().first < i) {
            pq.pop();
        }
        while (events[i] > k) {
            ans.emplace_back(pq.top().second);
            events[i]--;
            events[pq.top().first + 1]++;
            pq.pop();
        }
    }

    sort(begin(ans), end(ans));
    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}