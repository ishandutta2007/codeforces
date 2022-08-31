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
    string p, h;
    cin >> p >> h;
    vector<int> d(26);
    vector<int> ans(26);
    int incorrect = 0;
    for(char a: p) {
      if (!ans[a - 'a']) {
          incorrect++;
      }
      ans[a - 'a']++;
    }
    int l = 0;
    for(char r : h) {
        d[r - 'a']++;
        if (d[r - 'a'] == ans[r - 'a']) {
            incorrect--;
        } else if (d[r - 'a'] == ans[r - 'a'] + 1) {
            incorrect++;
        }
        while (d[h[l] - 'a'] > ans[h[l] - 'a']) {
            d[h[l] - 'a']--;
            if (d[h[l] - 'a'] == ans[h[l] - 'a']) {
                incorrect--;
            }
            l ++;
        }
        if (!incorrect) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests; cin >> tests;
    range(i, tests) {
        solve();
    }
    return 0;
}