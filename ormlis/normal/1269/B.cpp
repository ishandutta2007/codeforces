#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

using namespace std;
vector<int> a, b;

int n, m;

int sub(int a1, int b1) {
    if (a1 - b1 < 0) {
        return a1 - b1 + m;
    }
    return a1 - b1;
}

int check(int x) {
    int prev = -1;
    range(i, n) {
        if (sub(b[(i + x) % n], a[i]) == prev || prev == -1) {
            if(prev == -1) {
                prev = sub(b[(i + x) % n], a[i]);
            }
        } else {
            return 1e9;
        }
    }
    return prev;
}


void solve() {
    cin >> n >> m;
    a.resize(n); b.resize(n);
    range(i, n) {
        cin >> a[i];
    }
    range(i, n) {
        cin >> b[i];
    }
    sort(all(a)); sort(all(b));
    int ans = 1e9;
    range(i, n) {
        ans = min(check(i), ans);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}