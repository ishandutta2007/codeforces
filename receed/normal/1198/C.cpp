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
using ld = long double;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int t, n, m, u, v;
    cin >> t;
    rep(z, t) {
        cin >> n >> m;
        vector<int> p(3 * n + 1), ans;
        rep(i, m) {
            cin >> u >> v;
            if (!p[u] && !p[v]) {
                p[u] = p[v] = 1;
                ans.push_back(i + 1);
            }
        }
        if (ans.size() >= n) {
            cout << "Matching\n";
            rep(i, n)
                cout << ans[i] << ' ';
        }
        else {
            cout << "IndSet\n";
            int nc = 0;
            for (int i = 1; i <= 3 * n; i++)
                if (!p[i] && nc < n) {
                    cout << i << ' ';
                    nc++;
                }
        }
        cout << '\n';
    }
}