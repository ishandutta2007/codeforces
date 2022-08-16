#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e3+10, MOD = 1e9+7;

int n, m, b[MAXN];
string s, a[MAXN];

vector<ar<int, 26>> nxt[MAXN];
ar<int, 26> nxt_word[MAXN];

pair<int, int> dp[MAXN][MAXN];

pair<int, int> nxt_occ(pair<int, int> c, int x) {
    if (c == make_pair(-1, -1)) return {-1, -1};

    int word = c.first, loc = c.second;
    if (word >= m) {
        return {-1, -1};
    }

    if (nxt[b[word]][loc][x] != -1) {
        return {word, nxt[b[word]][loc][x]};
    }
    if (nxt_word[word+1][x] != -1) {
        int new_word = nxt_word[word+1][x];
        return {new_word, nxt[b[new_word]][0][x]};
    }
    return {-1, -1};
}
pair<int, int> inc(pair<int, int> c) {
    if (c == make_pair(-1, -1)) return {-1, -1};

    int word = c.first, loc = c.second;
    if (loc+1 == sz(a[b[word]])) {
        return {word+1, 0};
    }
    return {word, loc+1};
}
pair<int, int> comb(pair<int, int> a, pair<int, int> b) {
    if (a == make_pair(-1, -1)) return b;
    if (b == make_pair(-1, -1)) return a;
    return min(a, b);
}
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> b[i], --b[i];
    cin >> s;

    for (int i = 0; i < n; i++) {
        int k = sz(a[i]);
        nxt[i].resize(k);

        auto& cur = nxt[i];
        for (int j = k-1; j >= 0; j--) {
            if (j == k-1) cur[j].fill(-1);
            else cur[j] = cur[j+1];
            cur[j][a[i][j]-'a'] = j;
        }
    }
    nxt_word[m].fill(-1);
    for (int i = m-1; i >= 0; i--) {
        if (i == m-1) nxt_word[i].fill(-1);
        else nxt_word[i] = nxt_word[i+1];
        for (int j = 0; j < 26; j++) if (nxt[b[i]][0][j] != -1) {
            nxt_word[i][j] = i;
        }
    }

    int ans = 0;
    for (int i = 0; i < sz(s); i++) {
        for (int j = 0; j <= sz(s); j++) {
            if (!j) {
                dp[i][j] = {0, 0};
                continue;
            }
            dp[i][j] = {-1, -1};
            if (i) dp[i][j] = comb(dp[i][j], dp[i-1][j]);
            
            pair<int, int> prv{-1, -1};
            if (i) prv = dp[i-1][j-1];
            else if (j == 1) prv = {0, 0};

            pair<int, int> go = nxt_occ(prv, s[i]-'a');

            if (go != make_pair(-1, -1)) {
                dp[i][j] = comb(dp[i][j], inc(go));
            }

            if (dp[i][j] != make_pair(-1, -1)) {
                ans = max(ans, j);
            }
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}