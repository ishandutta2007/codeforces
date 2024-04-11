#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define y1 qwe

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 1e6 + 5;

LL m;
LL h1, a1, x1, y1;
LL h2, a2, x2, y2;

int used[MAXN];
int dist[MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;

    LL tmp = h1;
    int cycle1 = -1;
    int ftime1 = -1;
    int c = 0;
    while (true) {
        //cerr << tmp << endl;
        used[tmp]++;        
        if (used[tmp] == 3) {
            break;
        }
        if (used[tmp] == 1 && tmp == a1) {
            ftime1 = c;
        }
        if (used[tmp] == 2 && tmp == a1) {
            cycle1 = c - dist[tmp];
        }
        dist[tmp] = c;
        tmp = (tmp * x1 + y1) % m;
        ++c;
    }


    memset(dist, 0, sizeof dist);
    memset(used, 0, sizeof used);
    tmp = h2;
    int cycle2 = -1;
    c = 0;
    int ftime2 = -1;
    while (true) {
        used[tmp]++;
        
        if (used[tmp] == 3) {
            break;
        }
        if (used[tmp] == 1 && tmp == a2) {
            ftime2 = c;
        }
        if (used[tmp] == 2 && tmp == a2) {
            cycle2 = c - dist[tmp];
        }
        dist[tmp] = c;
        tmp = (tmp * x2 + y2) % m;
        ++c;
    }

    //cerr << ftime1 << " " << cycle1 << endl;

    if (cycle1 == -1) {
        if (cycle2 == -1) {
            if (ftime1 == -1 || ftime2 == -1 || ftime1 != ftime2) {
                cout << -1 << endl;
                return 0;
            }
            cout << ftime1 << endl;
            return 0;
        }
        if (ftime1 == -1) {
            cout << -1 << endl;
            return 0;
        }
        if (ftime1 >= ftime2 && (ftime1 - ftime2) % cycle2 == 0) {
            cout << ftime1 << endl;
            return 0;
        }
        cout << -1 << endl;
        return 0;
    }

    if (cycle2 == -1) {
        if (ftime2 == -1) {
            cout << -1 << endl;
            return 0;
        }
        if (ftime2 >= ftime1 && (ftime2 - ftime1) % cycle1 == 0) {
            cout << ftime2 << endl;
            return 0;
        }
        cout << -1 << endl;
        return 0;
    }

    LL ans = ftime1;

    c = 0;

    while (ans < ftime2 || (ans - ftime2) % cycle2 != 0) {
        ans += cycle1;
        if (c - 1000 == 0) {
            c = 0;
            if (clock() > CLOCKS_PER_SEC * 0.8) {
                cout << -1 << endl;
                return 0;
            }
        }
        ++c;
    }

    cout << ans << endl;

    return 0;
}