/*

      #     #     #####  #####  #           #  #
     # #   # #    #      #   #  #     #     #  #
    #   # #   #   #####  #   #   #   # #   #   #
   #     #     #  #      #   #    # #   # #     
   #           #  #####  #####     #     #     @

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ld EPS = (ld) 1e-7;
const ll MOD = (ll) 1e9 + 7;

#define sz(x) (int) (x).size()
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back((x))
#define all(x) (x).begin(), (x).end()
#define lb(s, t, x) (int) (lower_bound(s, t, x) - s)
#define ub(s, t, x) (int) (upper_bound(s, t, x) - s)
#define rep(i, f, t) for (int i = f; i < t; i++)

ll power(ll x, ll y, ll mod = MOD) {
    if (y == 0) {
        return 1;
    }
    if (y & 1) {
        return power(x, y - 1, mod) * x % mod;
    } else {
        ll tmp = power(x, y / 2, mod);
        return tmp * tmp % mod;
    }
}

template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

template<typename T> void read(T first, T last) {
    while (first != last) {
        cin >> *(first++);
    }
}

template<typename T> void print(T first, T last) {
    while (first != last) {
        cout << *(first++) << " ";
    }
    cout << "\n";
}  

void run();

#define TASK ""

int main() {
#ifdef LOCAL
    if (strlen(TASK) > 0) {
        cerr << "Reminder: you are using file i/o, filename: " TASK "!" << endl << endl;
    }
#endif
#ifndef LOCAL
    if (strlen(TASK)) {
        freopen(TASK ".in", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
#endif
    run();
    return 0;
}

// == SOLUTION == //

const int N = 1005;

int n, m;
string f[N];
bool a[2][N][N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool ok(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m && f[x][y] != '*';
}

void go(int x, int y, int t) {
    a[t][x][y] = 1;
    for (int dir = 0; dir < 4; dir++) {
        int X = x;
        int Y = y;
        while (ok(X + dx[dir], Y + dy[dir])) {
            X += dx[dir];
            Y += dy[dir];
            a[t][X][Y] = 1;
        }
    }
}

void run() {
    cin >> n >> m;
    int x0, y0, x1, y1;
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        for (int j = 0; j < m; j++) {
            if (f[i][j] == 'S') {
                x0 = i;
                y0 = j;
            } else if (f[i][j] == 'T') {
                x1 = i;
                y1 = j;
            }
        }
    }
    
    vector<pair<int, int>> q;
    go(x0, y0, 0);
    go(x1, y1, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[0][i][j]) q.pb(mp(i, j));
        }
    }
    for (auto &it : q) {
        go(it.first, it.second, 0);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[0][i][j] && a[1][i][j]) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}