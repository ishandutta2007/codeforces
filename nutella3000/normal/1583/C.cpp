#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld long double


const int inf = 1e9 + 7;

int n, m;
vector<string> s;
vector<vector<int>> le, up;

void run() {
    cin >> n >> m;
    s.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    le.resize(n, vector<int>(m));
    up.resize(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            le[i][j] = j;
            if (s[i][j] == 'X') continue;
            if (i == 0) up[i][j] = 1;
            else if (s[i - 1][j] != 'X') {
                le[i][j] = le[i - 1][j];
                up[i][j] = up[i - 1][j];
            }
            if (j == 0) le[i][j] = -1;
            else {
                chkmin(le[i][j], le[i][j - 1]);
                up[i][j] |= up[i][j - 1];
            }
        }
    }
    vector<bool> a(m), b(m);
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (s[i][j] == 'X') a[j] = true;
            if (i && j < m - 1 && s[i][j] == 'X' && s[i - 1][j + 1] == 'X')
             b[j] = true;
        }
    }

    vector<int> kuka, kukb;
    for (int i = 0; i < m; ++i) {
        if (a[i]) kuka.pb(i);
        if (b[i]) kukb.pb(i);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x1, x2; cin >> x1 >> x2; --x1;
        int t1 = lower_bound(all(kuka), x1) - kuka.begin();
        int t2 = lower_bound(all(kukb), x1) - kukb.begin();
        bool q = false;
        if (t2 != size(kukb) && kukb[t2] < x2 - 1) q = true;
        cout << (!q ? "YES" : "NO") << endl;
    }
}


signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}