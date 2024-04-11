#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
//using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

/*
typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 1e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int nxt[maxN][26];
int prv[maxN][26];
int fw[26][maxN];

int mex(vector<int> &a) {
    vector<bool> was(a.size() + 1);
    for (auto &x : a) {
        if (x < was.size()) was[x] = true;
    }
    range(i, (int) was.size()) if (!was[i]) return i;
    return -1;
}

int dp1[maxN][26];
int dp2[maxN][26];

int solve(int l, int r) {
    if (l + 1 == r) return 0;
    vector<int> can;
    range(ch, 26) {
        int L = nxt[l][ch];
        int R = prv[r][ch];
        if (L > R) continue;
        int res = fw[ch][L] ^fw[ch][R] ^dp1[l][ch] ^dp2[r][ch];
        can.push_back(res);
    }
    return mex(can);
}


void solve() {
    string s;
    cin >> s;
    vector<ar<int, 5>> q;
    // [len, l, r, char, tp]
    int m;
    cin >> m;
    int n = s.size();
    vector<int> last(26, -1);
    for (int i = 1; i <= n + 1; ++i) {
        range(ch, 26) {
            prv[i][ch] = last[ch];
        }
        if (i <= n) last[s[i - 1] - 'a'] = i;
    }
    range(ch, 26) last[ch] = n + 1;
    for (int i = n; i >= 0; --i) {
        if (i != n) last[s[i] - 'a'] = i + 1;
        range(ch, 26) {
            nxt[i][ch] = last[ch];
        }
    }
    for (int r = 1; r <= n + 1; ++r) {
        range(ch, 26) {
            fw[ch][r] = fw[ch][r - 1];
        }
        vector<int> ord(26);
        iota(all(ord), 0);
        sort(all(ord), [&](const int &i, const int &j) {
            return prv[r][i] > prv[r][j];
        });
        for (auto &ch : ord) {
            if (prv[r][ch] == -1) break;
            dp2[r][ch] = solve(prv[r][ch], r);
        }
        if (r == n + 1) break;
        int ch = s[r - 1] - 'a';
        if (prv[r][ch] != -1) {
            fw[ch][r] ^= dp2[r][ch];
        }
        int L = prv[r][ch];
        range(ch2, 26) {
            int cur = prv[r][ch2];
            while (cur >= L && cur != -1) {
                dp1[cur][ch] = solve(cur, r);
                cur = prv[cur][ch2];
            }
        }
        if (L == -1) {
            dp1[0][ch] = solve(0, r);
        }
    }
    range(_, m) {
        int l, r;
        cin >> l >> r;
        r++;
        l--;
        if (solve(l, r) == 0) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}