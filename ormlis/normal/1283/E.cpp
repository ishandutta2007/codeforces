#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>
#include <math.h>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
using namespace std;

int n, m;

void solve() {
    cin >> n;
    multiset<int> s;
    range(i, n) {
        int x; cin >> x;
        s.insert(x);
    }
    vector<int> d(n + 2, 0);
    vector<int> d2(n + 2, 0);
    for(auto x: s) {
        if (!(d[x - 1] || d[x])) {
            d[x + 1] = 1;
        }
        if (!d2[x - 1]) {
            d2[x - 1] = 1;
        } else if (!d2[x]) {
            d2[x] = 1;
        } else if (!d2[x + 1]) {
            d2[x + 1] = 1;
        }
    }
    int ans1 = 0, ans2 = 0;
    range(i, n + 2) {
        ans1 += d[i];
        ans2 += d2[i];
    }
    cout << ans1 << ' ' << ans2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    tests = 1;
    range(i, tests) {
        solve();
    }
    return 0;
}