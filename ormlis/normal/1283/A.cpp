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

void solve() {
    int h, m; cin >> h >> m;
    cout << (24 - h - 1) * 60 + 60 - m << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    range(i, tests) {
        solve();
    }
    return 0;
}