#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int n, k, l[MAXN], r[MAXN], par[MAXN];
int nxt[MAXN], a[MAXN], loc[MAXN], open[MAXN];
bool take[MAXN];
string s;

int t = 0;
void dfs_one(int c, int p) {
    if (c == -1) return;
    par[c] = p;
    dfs_one(l[c], c);
    a[loc[c] = t++] = c;
    dfs_one(r[c], c);
   
}
bool should_double(int c) {
    return nxt[loc[c]] != -1 && s[nxt[loc[c]]] > s[c];
}
void dfs_two(int c, int p) {
    if (c == -1) return;
    if (p != -1) {
        open[c] = 1 + open[p];
    } else {
        open[c] = 1;
    }

    dfs_two(l[c], c);
    if (should_double(c) && open[c] <= k) {
        int me = c;
        while (me != -1 && !take[me]) {
            take[me] = 1;
            open[me] = 0;
            me = par[me];
            k--;
        }
    } else if (!take[c]) {
        open[c] = MOD;
    }

    dfs_two(r[c], c);
}
void solve() {
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i], --l[i], --r[i];
    }
    dfs_one(0, -1);
    nxt[n-1] = -1;
    for (int i = n-2; i >= 0; i--) {
        if (s[a[i+1]] != s[a[i]]) nxt[i] = a[i+1];
        else nxt[i] = nxt[i+1];
    }
    dfs_two(0, -1);
    string ans;
    for (int i = 0; i < n; i++) {
        int c = a[i];
        ans += s[c];
        if (take[c]) ans += s[c];
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}