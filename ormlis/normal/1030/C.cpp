#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>
#include <cmath>
#include <unordered_map>
#include <array>

#define ll long long
#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int all = 0;
    range(i, n) {
        char b;
        cin >> b;
        a[i] = b - '0';
        all += a[i];
    }
    int cur = 0;
    range(i, n) {
        cur += a[i];
        int cur2 = 0; int count = 0;
        for(int j = i + 1; j < n; ++j) {
            cur2 += a[j];
            if (cur2 == cur) {cur2 = 0; count++;}
        }
        if (cur2 == 0 && count) {
            cout << "YES"; return;
        }
    }
    cout << "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}