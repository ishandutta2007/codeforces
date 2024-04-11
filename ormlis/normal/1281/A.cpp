#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
using namespace std;

void solve() {
    string s;
    cin >> s;
    int r = (int)s.size() - 1;
    if (s[r] == 'o') cout << "FILIPINO";
    if (s[r] == 'u') cout << "JAPANESE";
    if (s[r] == 'a') cout << "KOREAN";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tests;
    cin >> tests;
    range(i, tests) {
        solve();
    }
    return 0;
}