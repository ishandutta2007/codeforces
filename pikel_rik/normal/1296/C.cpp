#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> s;

        pair<int, int> p;
        int ans1 = 0, ans2 = 0;

        map<pair<int, int>, int> mp;

        for (int i = 1; i <= n; i++) {
            char c = s[i - 1];
            if (c == 'L')
                p.first--;
            else if (c == 'R')
                p.first++;
            else if (c == 'U')
                p.second++;
            else p.second--;

            if (p.first == 0 and p.second == 0) {
                if (!ans1) {
                    ans1 = 1;
                    ans2 = i;
                }
            }

            if (mp[p]) {
                if (!ans1) {
                    ans1 = mp[p] + 1;
                    ans2 = i;
                }
                else if (i - mp[p] < ans2 - ans1 + 1) {
                    ans1 = mp[p] + 1;
                    ans2 = i;
                }
            }
            mp[p] = i;
        }

        if (ans1)
            cout << ans1 << " " << ans2 << "\n";
        else cout << "-1\n";
    }
    return 0;
}