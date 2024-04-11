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
	int t, n;
    string s;
    cin >> t;
    rep(z, t) {
        cin >> n >> s;
        vector<int> ans(n);
        int fl = 1;
        rep(q, 10) {
            int f = 0, m1 = 0, m2 = q, d;
            rep(i, n) {
                d = s[i] - '0';
                if (d >= m2) {
                    m2 = d;
                    ans[i] = 1;
                }
                else if (d >= m1) {
                    m1 = d;
                    ans[i] = 0;
                }
                else {
                    f = 1;
                    break;
                }
            }
            if (!f && m1 <= q) {
                fl = 0;
                break;
            }
        }
        if (fl)
            cout << "-";
        else
            for (int i : ans)
                cout << i + 1;
        cout << '\n';
    }
}