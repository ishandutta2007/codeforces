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

int n;
vector<ll> d;

void solve() {
    int a, b;
    cin >> a >> b;
    auto j = (int) (lower_bound(all(d), abs(b-a)) - d.begin());
    if (d[j] % 2 == abs(a - b) % 2) {
        cout << j;
    } else if (j % 2) {
        cout << j + 2;
    } else {
        cout << j + 1;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    ll cur = 0;
    int i = 1;
    d.push_back(0);
    while (cur < 1e9) {
        cur += i;
        d.push_back(cur);
        i++;
    }
    cin >> tests;
    range(i, tests) {
        solve();
    }
    return 0;
}