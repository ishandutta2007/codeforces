#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e2+10, MOD = 1e9+7;

bool dead[MAXN][MAXN], vis1[MAXN][MAXN], vis2[MAXN][MAXN], vis3[MAXN][MAXN], in[MAXN][MAXN];

vector<ar<int, 2>> adj(ar<int, 2> c) {
    vector<ar<int, 2>> ans{{c[0]+1, c[1]}, {c[0]-1, c[1]}};
    if (c[0]&1) ans.push_back({c[0]-1, c[1]+1});
    else ans.push_back({c[0]+1, c[1]-1});
    return ans;
}
bool bounds(ar<int, 2> c) {
    return 0 <= c[0] && 0 <= c[1];
}
int cnt_bad(int a, int b) {
    int ans = 0;
    for (auto nxt : adj({a, b})) if (bounds(nxt)) {
        if (dead[nxt[0]][nxt[1]]) ans++;
    }
    return ans;
}
int cnt_in(int a, int b) {
    int ans = 0;
    for (auto nxt : adj({a, b})) if (bounds(nxt)) {
        if (in[nxt[0]][nxt[1]]) ans++;
    }
    return ans;
}
bool bad(int a, int b){ return cnt_bad(a, b) >= 2; }

int dfs(ar<int, 2> c) {
    int ans = 1;
    for (auto nxt : adj(c)) if (bounds(nxt)) {
        if (!dead[nxt[0]][nxt[1]] && bad(nxt[0], nxt[1])) {
            dead[nxt[0]][nxt[1]] = 1;
            if (bad(nxt[0], nxt[1])) {
                dead[nxt[0]][nxt[1]] = 1;
                ans += dfs(nxt);
            }
        }
    }
    return ans;
}
bool cycle(ar<int, 2> c, ar<int, 2> p) {
    vis1[c[0]][c[1]] = 1;
    for (auto nxt : adj(c)) if (bounds(nxt) && nxt != p && dead[nxt[0]][nxt[1]]) {
        if (vis1[nxt[0]][nxt[1]]) return 1;
        if (cycle(nxt, c)) return 1;
    }
    return 0;
}
bool can_cheap(ar<int, 2> c) {
    if (in[c[0]][c[1]] && cnt_in(c[0], c[1])) return 1;
    if (!in[c[0]][c[1]] && cnt_in(c[0], c[1]) == 2) return 1;
    vis2[c[0]][c[1]] = 1;
    for (auto nxt : adj(c)) if (bounds(nxt) && !vis2[nxt[0]][nxt[1]] && dead[nxt[0]][nxt[1]]) {
        if (can_cheap(nxt)) return 1;
    }
    return 0;
}
int get_sz(ar<int, 2> c) {
    int ans = 1;
    vis3[c[0]][c[1]] = 1;
    for (auto nxt : adj(c)) if (bounds(nxt) && !vis3[nxt[0]][nxt[1]] && dead[nxt[0]][nxt[1]]) {
        ans += get_sz(nxt);
    }
    return ans;
}
void solve(){
    int m; cin >> m;
    vector<ar<int, 2>> q; q.reserve(MAXN*MAXN);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        dead[a][b] = in[a][b] = 1;
        dfs({a, b});
    }
    int ans = 0;
    for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) if (in[i][j]) {
        ans += !in[i][j];
        for (auto nxt : adj({i, j})) if (!bounds(nxt) || !in[nxt[0]][nxt[1]]) {
            ans++; 
        } 
    }
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) if (dead[i][j] && !vis1[i][j]) {
            ans -= 2;
            if (cycle({i, j}, {-1, -1})){ cout << "SICK\n"; return; }
            if (!can_cheap({i, j}) && get_sz({i, j}) > 1) ans -= 2;
        }
    }
    cout << "RECOVERED\n";
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}