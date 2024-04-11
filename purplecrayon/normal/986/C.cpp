#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = (1<<22)+10;
//const int MAXN = 5e6+10, MOD = 1e9+7;

int n, m;
int a[MAXN], b[MAXN];
bitset<2*MAXN> vis;

int get_id(int b, int i) {
    return b*m+i;
}
queue<int> q;
void go(int nxt){ if (!vis[nxt]){ q.push(nxt); vis[nxt] = 1; } }
void dfs(int c) {
    go(c);
    while (sz(q)) {
#define c c_current
        int c = q.front(); q.pop();
        if (c >= m) { //b == 1 -> i'm at some virtual node
            int i = c-m;
            int opp = (~i)&((1<<n)-1);
            if (b[opp] != -1) {
                go(get_id(0, b[opp]));
            }
            for (int j = 0; j < n; j++) if ((i>>j)&1^1) {
                go(get_id(1, i|(1<<j)));
            }
        } else { //b == 0 -> i'm at some index
            int i = c;
            go(get_id(1, a[i]));
            for (int j = 0; j < n; j++) if ((a[i]>>j)&1^1) {
                go(get_id(1, a[i]|(1<<j)));
            }
        }
#undef c
    }
}
void solve(){
    cin >> n >> m;
    memset(b, -1, sizeof(b));
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        b[a[i]] = i;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (!vis[get_id(0, i)]) {
            ans++;
            dfs(get_id(0, i));
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