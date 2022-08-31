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


void solve() {
    cin >> n;
    int sum = 0;
    int b;
    int summ = 0;
    vector<int> a(2 * n);
    range(i, 2 * n) {
        cin >> a[i];
        if (a[i] == 2) {
            a[i] = -1;
        }
        summ += a[i];
    }
    map<int, int> ans;
    int itog = 2 * n;
    ans[0] = -1;
    range(i, n) {
        b = a[i];
        sum += b;
        ans[sum] = i;
    }
    sum -= a[n - 1];
    range(i, n + 1) {
        b = a[i + n - 1];
        sum += b;
        if (ans.find(sum - summ) != ans.end()) {
            itog = min(itog, i + n - ans[sum - summ] - 1);
        }
    }
    cout << itog << '\n';
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