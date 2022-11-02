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
const int max_n = 4e5 + 3;

int n, m;
int a[max_n];
string s[max_n];

vector<pii> bl[max_n];
vector<bool> good[max_n];
vector<int> up[max_n], le[max_n], ri[max_n];


int find(pii v, int id) {
    int l = -1, r = size(bl[id]);
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (bl[id][mid].se < v.fi) r = mid;
        else l = mid;
    }
    return l == -1 ? l : up[id][l];
}

void run() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < m; ++i)
        cin >> a[i];

    for (int i = 0; i < m; ++i) {
        int cnt = 0, lst = -1;
        for (int j = n - 1; j >= -1; --j) {
            if (j == -1 || s[j][i] == '.') {
                if (lst != -1) {
                    good[i].pb(cnt >= a[i]);
                    bl[i].pb(j + 1, lst);
                }
                lst = -1;
            }
            else {
                ++cnt;
                if (lst == -1) lst = j;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < size(bl[i]); ++j) {
            up[i].pb(j);
            le[i].pb(good[i][j] ? i : m);
            ri[i].pb(good[i][j] ? i : -1);
        }
    }

    for (int i = 1; i < m; ++i) {
        for (int j = size(bl[i]) - 1; j >= 0; --j) {
            int k = find(bl[i][j], i - 1);
            if (k != -1) {
                k = find(bl[i - 1][k], i);
                if (k > j) up[i][j] = up[i][k];
            }
        }
    }
    for (int i = m - 2; i >= 0; --i) {
        for (int j = size(bl[i]) - 1; j >= 0; --j) {
            int k = find(bl[i][j], i + 1);
            if (k != -1) {
                k = find(bl[i + 1][k], i);
                if (k > j) up[i][j] = up[i][k];
            }
        }
    }
    
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < size(bl[i]); ++j) {
            int k = find(bl[i][up[i][j]], i - 1);
            if (good[i][j] && k >= 0) chkmin(le[i][j], le[i - 1][k]);
        }
    }
    for (int i = m - 2; i >= 0; --i) {
        for (int j = 0; j < size(bl[i]); ++j) {
            int k = find(bl[i][up[i][j]], i + 1);
            if (good[i][j] && k >= 0) chkmax(ri[i][j], ri[i + 1][k]);
        }
    }

    vector<vector<int>> ad(m), rm(m + 1);
    for (int i = 0; i < m; ++i) {
        if (le[i].empty()) continue;
        auto [l, r] = tie(le[i].back(), ri[i].back());
        if (l <= r) {
            ad[l].pb(l);
            rm[r + 1].pb(l);
        }
    }
    multiset<int> qq;
    vector<int> dp(m);
    for (int i = 0; i < m; ++i) {
        for (int j : ad[i])
            qq.insert(j);
        for (int j : rm[i])
            qq.erase(qq.find(j));

        if (!a[i]) dp[i] = (i ? dp[i - 1] : 0);
        else {
            int k = (*qq.begin());
            dp[i] = (k ? dp[k - 1] : 0) + 1;
        }
    }
    cout << dp[m - 1] << endl;
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);

#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}