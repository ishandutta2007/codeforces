#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef bitset<26> bs;



int main() {
    fast;
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> b(n);
    foru(i, 0, n)cin >> b[i];
    vector<vector<bool>> a(n, vector<bool>(m, false));
    int cnt = 0;
    vector<int> cntcol(m, 0);
    foru(i, 0, n) {
        foru(j, 0, m) {
            a[i][j] = (b[i][j] == '*');
            cnt += a[i][j];
            cntcol[j] += a[i][j];
        }
    }
    int lastfilled = (cnt / n) - 1;
    int rem = cnt % n;
    int inPlace = 0;
    for (int i = 0; i <= lastfilled; i++) {
        inPlace += cntcol[i];
    }
    if (lastfilled != m - 1) {
        for (int i = 0; i < rem; i++)inPlace += a[i][lastfilled + 1];
    }
    while (q--) {
        int x, y;
        cin >> x >> y; x--; y--;
        if (a[x][y]) {
            cnt--;
            rem = cnt % n;
            lastfilled = (cnt / n) - 1;
            int sy = cnt / n, sx = cnt % n;
            if (a[sx][sy])inPlace--;
            if (y < sy || (y == sy && sx > x))inPlace--;
            a[x][y] = 0;
        }
        else {
            int sy = cnt / n, sx = cnt % n;
            a[x][y] = 1;
            cnt++;
            if (a[sx][sy])inPlace++;
            if (y < sy || (y == sy && sx > x))inPlace++;
            rem = cnt % n;
            lastfilled = (cnt / n) - 1;
        }
        cout << cnt - inPlace << '\n';
    }
    return 0;
}