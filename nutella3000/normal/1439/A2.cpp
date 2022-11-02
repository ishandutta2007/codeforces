#include <bits/stdc++.h>
 
using namespace std;


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
 
const ll inf = 1e9 + 7;
const int max_n = 101;

int a[max_n][max_n];
vector<pii> r[3];

void g(int x, int y, int id) {
    //a[x][y] = 1 - a[x][y];
    r[id].emplace_back(x, y);
}

void f1(int x, int y) {
    int cnt = 0;
    if (a[x][y] == 1) g(x, y, cnt++);
    if (a[x + 1][y] == 1) g(x + 1, y, cnt++);
    if (cnt == 0) return;
    g(x, y + 1, cnt++);
    if (cnt != 3) g(x + 1, y + 1, cnt++);

    for(int i = 0;i < 3;i++) {
        pii v = r[i].back();
        a[v.fi][v.se] = 1 - a[v.fi][v.se];
    }
}

void f2(int x, int y) {
    int cnt = 0;

    if (a[x][y] == 1) g(x, y, cnt++);
    if (a[x][y + 1] == 1) g(x, y + 1, cnt++);
    if (cnt == 0) return;
    g(x + 1, y, cnt++);
    if (cnt != 3) g(x + 1, y + 1, cnt++);

    for(int i = 0;i < 3;i++) {
        pii v = r[i].back();
        a[v.fi][v.se] = 1 - a[v.fi][v.se];
    }
}

void f(int x, int y) {
    int c = 0, c1 = 0;
    for(int i = 0;i <= 1;i++) {
        for(int j = 0;j <= 1;j++)
            c1 += a[x + i][y + j];
    }

    if (c1 == 0) return;
    for(int i = x;i <= x + 1;i++) {
        for(int j = y;j <= y + 1;j++) {
            if (c1 == 2 && a[i][j] == 0) g(i, j, c++);
            else if(c1 != 2 && a[i][j] == 1) g(i, j, c++);
        }
    }
    for(int i = x;i <= x + 1;i++) {
        for(int j = y;j <= y + 1;j++) {
            if (c == 3) continue;
            if (c1 == 2 && a[i][j] == 1) g(i, j, c++);
            if (c1 != 2 && a[i][j] == 0) g(i, j, c++);
        }
    }
    for(int i = 0;i < 3;i++) {
        pii v = r[i].back();
        a[v.fi][v.se] = 1 - a[v.fi][v.se];
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    r[0].clear(); r[1].clear(); r[2].clear();

    for(int i = 0;i < n;i++) {
        string s;
        cin >> s;
        for(int j = 0;j < m;j++) {
            a[i][j] = s[j] - '0';
        }
    }

    for(int i = 0;i < n - 1;i++) {
        for(int j = 0;j < m;j+= 2) {
            if (i + 2 == n) j--;
            if (j == m - 1) j--;
            if (j == m - 2 && i + 2 == n) break;
            if (i + 2 != n) f2(i, j);
            else f1(i, j);
        }

        if (i + 2 == n) {
            for(int it = 0;it < 4;it++)
                f(i, m - 2);
        }
    }

    /*for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            cout << a[i][j] << " ";
        cout << endl;
    }*/

    cout << sz(r[0]) << endl;
    for(int i = 0;i < sz(r[0]);i++) {
        cout << r[0][i].fi + 1 << " " << r[0][i].se + 1 << " " << r[1][i].fi + 1 << " " << r[1][i].se + 1 << " " <<
         r[2][i].fi + 1 << " " << r[2][i].se + 1 << endl;
    }
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}