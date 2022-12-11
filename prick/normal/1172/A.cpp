#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

const int inf = 1e8;

int solve1(int n, vector<int> a, vector<int> b) {
    auto it = find(begin(a), end(a), 1);
    if (it == end(a)) {
        return inf;
    }
    int pos = it - begin(a);
    for (int i = pos; i < n; ++i) {
        if (a[i] != i - pos + 1) {
            return inf;
        }
    }
    vector<char> has(n + 1);
    for (auto i: b) {
        has[i] = true;
    }
    for (int i = 0; i < pos; ++i) {
        if (!has[a.back() + i + 1]) {
            return inf;
        }
        has[a[i]] = true;
    }
    return pos;
}

bool f(int n, vector<int> a, vector<int> b, int ans) {
    vector<char> has(n + 1);
    for (auto i: b) {
        has[i] = true;
    }
    for (int i = 0; i < ans; ++i) {
        has[a[i]] = true;
    }
    for (int i = ans; i < n; ++i) {
        if (!has[i - ans + 1]) {
            return false;
        }
        has[a[i]] = true;
    }
    return true;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    swap(a, b);
    
    int ans1 = solve1(n, a, b);
    
    int left = -1, right = n;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (f(n, a, b, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    
    cout << min(ans1, right + n) << '\n';
}