#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    vector<int> ans(n);

    int ptr = 0;
    for (int i = 1; i < n; i += 2) {
        ans[i] = a[ptr++];
    }
    for (int i = 0; i < n; i += 2) {
        ans[i] = a[ptr++];
    }

    int c = 0;
    for (int i = 1; i < n - 1; i++) {
        c += ans[i] < ans[i - 1] and ans[i] < ans[i + 1];
    }

    cout << c << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
    return 0;
}