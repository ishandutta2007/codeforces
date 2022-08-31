#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>

#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

int a1, b1, c1, a2, b2, c2, d1, d2, d3, d4, d5, d6, d7;

bool check(int dd2, int dd3, int dd5) {
    int aa1 = a1, bb1 = b1, cc1 = c1, aa2 = a2, bb2 = b2, cc2 = c2;
    bb1 -= dd5; cc1 -= dd5; bb2 -= d5 - dd5; cc2 -= d5 - dd5;
    aa1 -= dd2; bb1 -= dd2; aa2 -= d2 - dd2; bb2 -= d2 - dd2;
    aa1 -= dd3; cc1 -= dd3; cc2 -= d3 - dd3; aa2 -= d3 - dd3;
    if (min(aa1, min(aa2, min(bb1, min(bb2, min(cc1, cc2))))) < 0) return false;
    int k = min(min(d1, aa1), min(bb1, cc1));
    int f = d1 - k;
    if (f > min(aa2, min(bb2, cc2))) return false;
    aa1 -= k; bb1 -= k; cc1 -= k;
    aa2 -= f; bb2 -= f; cc2 -= f;
    if (aa1 + aa2 < d4) return false;
    if (bb1 + bb2 < d6) return false;
    if (cc1 + cc2 < d7) return false;
    cout << k << ' ' << dd2 << ' ' << dd3 << ' ' << min(aa1, d4) << ' ' << dd5 << ' ' << min(bb1, d6) << ' ' << min(cc1, d7) << '\n';
    return true;
}

void solve() {
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> d1 >> d2 >> d3 >> d4 >> d5 >> d6 >> d7;
    range(i, d2 + 1) {
        range(j, d3 + 1) {
            range(k, d5 + 1) {
                if (check(i, j, k)) return;
            }
        }
    }
    cout << -1 << '\n';
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}