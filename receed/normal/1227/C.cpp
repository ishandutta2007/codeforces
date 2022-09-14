#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int t, n, k;
    cin >> t;
    rep(z, t) {
        string s, t;
        cin >> n >> k >> s;
        rep(i, n / 2 - k + 1)
            t.push_back('(');
        rep(i, n / 2 - k + 1)
            t.push_back(')');
        rep(i, k - 1) {
            t.push_back('(');
            t.push_back(')');
        }
        vector<pair<int, int>> ans;
        rep(i, n - 1) {
            if (s[i] == t[i])
                continue;
            int p = i;
            while (s[i] == s[p])
                p++;
            ans.push_back({i, p});
            swap(s[i], s[p]);
        }
        cout << ans.size() << '\n';
        for (auto &pp : ans)
            cout << pp.first + 1 << ' ' << pp.second + 1 << '\n';
    }

}