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

const int N = 300002;
int a[N], c1[N], c2[N], c3[N];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
    string s;
    cin >> n >> s;
    int mn = 0, sh = 0;
    deque<int> ps(n + 1);
    rep(i, n) {
        a[i] = (s[i] == '(' ? 1 : -1);
        ps[i + 1] = ps[i] + a[i];
        mn = min(mn, ps[i + 1]);
    }
    if (ps[n] != 0) {
        cout << "0\n1 1";
        return 0;
    }
    while (ps[0] > mn) {
        ps.pop_front();
        ps.push_back(ps[0]);
        sh++;
    }
    rep(i, n + 1)
        ps[i] -= mn;
    mn = 0;
    rep(i, n) {
        c1[i + 1] = c1[i] + (ps[i + 1] == mn ? 1 : 0);
        c2[i + 1] = c2[i] + (ps[i + 1] == mn + 1 ? 1 : 0);
        c3[i + 1] = c3[i] + (ps[i + 1] == mn + 2 ? 1 : 0);
    }
    int ans = c1[n], l = 0, r = 0, l1 = -1, ca, l2 = -1, r2 = -1, l3 = -1, r3;
    rep(i, n) {
        if (ps[i + 1] == mn) {
            if (ps[i + 1] < ps[i]) {
                ca = c2[i] - c2[r2 + 1];
                if (ca > ans) {
                    ans = ca;
                    l = r2 + 1;
                    r = i;
                }
            }
            r2 = i;
        }
        else if (ps[i + 1] == mn + 1) {
            if (ps[i + 1] < ps[i] && l1 != -1) {
                ca = c1[n] + c3[i] - c3[l1];
                if (ca > ans) {
                    ans = ca;
                    l = l1 + 1;
                    r = i;
                }
            }
            l1 = i;
            if (l3 == -1)
                l3 = i;
            r3 = i;
        }
    }
    ca = c2[l2 + 1] + c2[n] - c2[r2 + 1];
    if (ca > ans) {
        ans = ca;
        l = l2;
        r = r2 + 1;
    }
    ca = c3[l3] + c3[n] - c3[r3] + c1[r3] - c1[l3];
    if (ca > ans) {
        ans = ca;
        l = l3;
        r = r3 + 1;
    }
    cout << ans << '\n' << (l + sh) % n + 1 << ' ' << (r + sh) % n + 1;
}