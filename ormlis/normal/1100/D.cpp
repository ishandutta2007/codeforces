#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1000;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int r[maxN], c[maxN];
bool can[maxN][maxN];
pair<int, int> lad[668];
int xk, yk;

void go(int x, int y) {
    if (x == xk && y == yk) {
        if (x > 1) x--;
        else x++;
    }
    if (!can[x][y]) {
        x = xk;
    }
    cout << x << " " << y << endl;
    xk = x;
    yk = y;
    int k;
    cin >> k >> x >> y;
    if (k == -1) exit(0);
    if (k == 0) exit(0);
    r[lad[k].second]--;
    c[lad[k].first]--;
    can[lad[k].first][lad[k].second] = true;
    r[y]++;
    c[x]++;
    can[x][y] = false;
    lad[k] = {x, y};
}

void solve() {
    cin >> xk >> yk;
    range(i, maxN) range(j, maxN) can[i][j] = true;
    range(i, 666) {
        int x, y;
        cin >> x >> y;
        r[y]++;
        c[x]++;
        can[x][y] = false;
        lad[i + 1] = {x, y};
    }
    int cnt = 0;
    while (xk != 500 || yk != 500) {
        int x = xk, y = yk;
        if (xk < 500) x++;
        if (xk > 500) x--;
        if (yk < 500) y++;
        if (yk > 500) y--;
        go(x, y);
        cnt++;
    }
    vector<vector<int>> cntw = {{0, 0},
                                {0, 0}};
    for (int i = 1; i <= 666; ++i) {
        cntw[lad[i].first > 500][lad[i].second > 500]++;
    }
    int xc = 0, yc = 0;
    range(i, 2) {
        range(j, 2) {
            if (cntw[i][j] < 167) {
                if (i) xc = -1;
                else xc = 1;
                if (j) yc = -1;
                else yc = 1;
            }
        }
    }
    range(_, 499) {
        go(xk + xc, yk + yc);
    }
}

int main() {
    /*
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    */
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}