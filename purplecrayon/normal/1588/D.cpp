#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 10, MOD = 1e9+7;

const int A = 52;

int get_val(char c) {
    if ('a' <= c && c <= 'z') return c - 'a';
    if ('A' <= c && c <= 'Z') return c - 'A' + 26;
    assert(false);
}
char get_char(int c) {
    if (0 <= c && c < 26) return c + 'a';
    if (26 <= c && c < 52) return c - 26 + 'A';
    assert(false);
}

int n;
string s[MAXN];
vector<int> loc[A][MAXN];
vector<int> con[A][A][MAXN];
int max_dp[A][1<<MAXN];

vector<int> cur;
void rec(int c, int build, int cur_char) {
    if (c == n) {
        cur.push_back(build);
        return;
    }
    for (int i = 0; i < sz(loc[cur_char][c]); i++) {
        int new_build = build | (i << c);
        rec(c+1, new_build, cur_char);
    }
}
bool cmp(pair<int, int> one, pair<int, int> two) {
    if (one == make_pair(-1, -1)) return 1;
    if (two == make_pair(-1, -1)) return 0;

    for (int i = 0; i < n; i++) {
        int a = loc[one.second][i][(one.first >> i) & 1];
        int b = loc[two.second][i][(two.first >> i) & 1];
        if (a >= b) return 0;
    }
    return 1;
}
void solve() {
    cin >> n;

    for (int i = 0; i < A; i++) for (int j = 0; j < n; j++) loc[i][j].clear();
    for (int i = 0; i < A; i++) for (int j = 0; j < A; j++) for (int k = 0; k < n; k++) con[i][j][k].clear();

    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz(s[i]); j++)
            loc[get_val(s[i][j])][i].push_back(j);
    }
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A; j++) {
            for (int k = 0; k < n; k++) {
                con[i][j][k].assign(sz(loc[i][k]), MOD);
                for (int a = 0; a < sz(loc[i][k]); a++) {
                    for (int b = 0; b < sz(loc[j][k]); b++) {
                        if (loc[j][k][b] > loc[i][k][a]) {
                            con[i][j][k][a] = min(con[i][j][k][a], b);
                        }
                    }
                }
            }
        }
    }
    vector<pair<int, int>> a;
    for (int i = 0; i < A; i++) {
        cur.clear();
        rec(0, {}, i);
        for (auto x : cur) a.push_back(make_pair(x, i));
    }
    if (!sz(a)) {
        cout << 0 << '\n' << '\n';
        return;
    }

    memset(max_dp, 0, sizeof(max_dp));

    sort(a.begin(), a.end(), [&](pair<int, int> one, pair<int, int> two){
        for (int i = 0; i < n; i++) {
            int a = loc[one.second][i][(one.first >> i) & 1];
            int b = loc[two.second][i][(two.first >> i) & 1];
            if (a != b) return a < b;
        }
        return false;
    });
    vector<int> dp(sz(a), 1);
    for (int i = sz(a)-1; i >= 0; i--) {
        int cur_char = a[i].second;
        int cur_mask = a[i].first;
        for (int j = 0; j < A; j++) {
            bool bad = 0;
            int me = 0;
            for (int k = 0; k < n; k++) {
                int cur_val = con[cur_char][j][k][(cur_mask >> k) & 1];
                if (cur_val == MOD) { bad = 1; break; }
                me |= cur_val << k;
            }
            if (bad) continue;
            dp[i] = max(dp[i], 1 + max_dp[j][me]);
        }
        max_dp[cur_char][cur_mask] = max(max_dp[cur_char][cur_mask], dp[i]);

    }
    int ans = *max_element(dp.begin(), dp.end());
    cout << ans << '\n';

    pair<int, int> last{-1, -1};
    for (int i = 0; i < sz(a); i++) {
        if (dp[i] == ans && cmp(last, a[i])) {
            cout << get_char(a[i].second);
            last = a[i];
            ans--;
        }
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}