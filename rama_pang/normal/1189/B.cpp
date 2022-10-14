#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(begin(a), end(a));
    reverse(begin(a), end(a));
    if (a[0] >= a[1] + a[2]) {
        cout << "NO\n";
        return 0;
    }
    deque<int> ans;
    ans.emplace_back(a[0]);
    ans.emplace_back(a[1]);
    for (int i = 3; i < n; i++) {
        ans.emplace_back(a[i]);
    }
    ans.emplace_back(a[2]);
    cout << "YES\n";
    for (auto i : ans) {
        cout << i << " ";
    }
}