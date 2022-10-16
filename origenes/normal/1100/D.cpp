#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxk = 700;

pii rook[maxk];
bool vis[1000][1000];
int x, y;

int main() {
    cin >> x >> y;
    FOR(i, 1, 666) cin >> rook[i]._1 >> rook[i]._2;
    int dx = 0, dy = 0;
    if (x != 500) dx = 500 - x > 0 ? 1 : -1;
    if (y != 500) dy = 500 - y > 0 ? 1 : -1;
    while (x != 500) {
        x += dx;
        cout << x << ' ' << y << endl;
        int k;
        pii pos;
        cin >> k >> pos._1 >> pos._2;
        if (k == -1) return 0;
        rook[k] = pos;
    }
    while (y != 500) {
        y += dy;
        cout << x << ' ' << y << endl;
        int k;
        pii pos;
        cin >> k >> pos._1 >> pos._2;
        if (k == -1) return 0;
        rook[k] = pos;
    }
    int cnt[4] = {}, mmin = maxk, rec = 5;
    FOR(i, 1, 666) {
        int u = rook[i]._1, v = rook[i]._2;
        vis[u][v] = true;
        if (u < 500 && v < 500) cnt[0]++;
        else if (u < 500 && v > 500) cnt[1]++;
        else if (v < 500) cnt[2]++;
        else cnt[3]++;
    }
    REP(i, 4) if (mmin > cnt[i]) {
            mmin = cnt[i];
            rec = i;
        }
    switch (rec) {
        case 0: {
            dx = dy = 1;
            break;
        }
        case 1: {
            dx = 1, dy = -1;
            break;
        }
        case 2: {
            dx = -1, dy = 1;
            break;
        }
        case 3: {
            dx = dy = -1;
            break;
        }
        default:
            return -1;
    }
    while (true) {
        bool fx = false, fy = false;
        if (x != 1 && x != 999) x += dx, fx = true;
        if (y != 1 && y != 999) y += dy, fy = true;
        if (vis[x][y]) {
            assert(fx && fy);
            fx = false;
            x -= dx;
        }
        cout << x << ' ' << y << endl;
        int k;
        pii pos;
        cin >> k >> pos._1 >> pos._2;
        if (k == -1) return 0;
        vis[pos._1][pos._2] = true;
        vis[rook[k]._1][rook[k]._2] = false;
        rook[k] = pos;
    }
}