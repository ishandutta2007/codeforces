#include <bits/stdc++.h>
using namespace std;
     
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
mt19937 rnd;

const int inf = 2e9 + 3;
const int max_n = 4e2 + 3;

int n, m, k;
int a[max_n][max_n];

int mex(vector<int> b) {
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    if (size(b) && b.front() == 0) b.erase(b.begin());
    for (int i = 0; i < size(b); ++i)
        if (b[i] != i + 1) return i + 1;
    return size(b) + 1;
}
bool check(int x, int y) {
    return x >= 0 && y >= 0;
}

int mem(int x, int y) {
    vector<int> b;
    for (int i = -2; i <= 2; ++i) {
        for (int j = -2; j <= 2; ++j) {
            if (check(x + i, y + j)) b.pb(a[x + i][y + j]);
        }
    }
    return mex(b);
}

void run() {
    cin >> n >> m >> k;

    bool sw = false;
    if (n % 2 == 1) {
        sw = true;
        swap(n, m);
        k = n * m / 2 - k;
    }

    if (k % 2 == 0 && 2 * k <= (m / 2 * 2) * n) {
        cout << "YES" << endl;

        for (int i = 0; i < n; ++i)
            fill(a[i], a[i] + m, 0);
        for (int j = 0; j < m; j += 2) {
            for (int i = 0; i < n; i += 2) {
                if (!k) break;
                k -= 2;
                int val = mem(i, j);
                a[i][j] = a[i][j + 1] = val;
                val = mem(i + 1, j);
                a[i + 1][j] = a[i + 1][j + 1] = val;
            }
        }
        for (int i = 0; i < n; i += 2) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j]) continue;
                int val = mem(i, j);
                a[i][j] = a[i + 1][j] = val;
            }
        }
        if (sw) {
            vector<vector<int>> b(m, vector<int>(n));
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    b[j][i] = a[i][j];
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    a[i][j] = b[i][j];
            swap(n, m);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << char('a' + a[i][j] - 1);
            }
            cout << endl;
        }
    }
    else cout << "NO" << endl;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);

#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}