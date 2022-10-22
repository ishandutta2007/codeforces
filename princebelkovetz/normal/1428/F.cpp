#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 998244353, p = 239, N = 4e5 + 5;

string s;
int ans = 0;

vector <int> res, suf;

void solve(int l, int r) {
    if (l + 1 == r) {
        ans += (s[l] == '1');
        return;
    }
    
    int m = (l + r) / 2;
    solve(l, m), solve(m, r);
    
    int lx = m - 1, rx = m;
    while (lx >= l and s[lx] == '1')
        lx--;
    while (rx < r and s[rx] == '1')
        rx++;
    
    res[m] = (s[m] == '1');
    int serie = res[m];

    for (int i = m + 1; i < r; ++i) {
        if (s[i] == '1')
            serie++;
        else 
            serie = 0;
        res[i] = max(res[i - 1], serie);
    }

    res[m - 1] = (s[m - 1] == '1');
    serie = res[m - 1];
    for (int i = m - 2; i >= l; --i) {
        if (s[i] == '1')
            serie++;
        else
            serie = 0;
        res[i] = max(res[i + 1], serie);
    }

    // part I 
    for (int i = lx + 1; i < m; ++i) {
        int all = rx - m;
        ans += all * (all + 1) / 2 + (m - i) * all;
    }

    // part II
    for (int i = l; i <= lx; ++i) {
        int le = m - 1, ri = rx;
        while (le + 1 < ri) {
            int mid = (le + ri) / 2;
            if (mid - lx <= res[i]) le = mid;
            else ri = mid;
        }
        ans += res[i] * (ri - m);
        ans += (rx - ri) * (rx - ri + 1) / 2 + (ri - lx - 1) * (rx - ri);
    }

    // part III
    for (int i = r - 1; i >= rx; --i) {
        int le = lx, ri = m;
        while (le + 1 < ri) {
            int mid = (le + ri) / 2;
            if (rx - mid <= res[i]) ri = mid;
            else le = mid;
        }
        ans += res[i] * (m - le - 1);
        ans += (le - lx) * (le - lx + 1) / 2 + (rx - le - 1) * (le - lx);
    }

    // part IV
    suf[r] = 0;
    for (int i = r - 1; i >= rx; --i)
        suf[i] = suf[i + 1] + res[i];
    for (int i = l; i <= lx; ++i) {
        res[i] = max(res[i], rx - lx - 1);
        int le = rx - 1, ri = r;
        while (le + 1 < ri) {
            int mid = (le + ri) / 2;
            if (res[i] >= res[mid]) le = mid;
            else ri = mid;
        }
        ans += res[i] * (ri - rx);
        ans += suf[ri];
    }

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int n; cin >> n;
    res.resize(n);
    suf.resize(n + 1);
    cin >> s;
    solve(0, n);
    cout << ans << '\n';


    return 0;
}