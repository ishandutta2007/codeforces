#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define sz(a) ((int) a.size())
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const int inf = 1e15;
const int max_n = 5e3 + 4;
 
int n;
vector<int> dp[max_n][2];
vector<int> gr[max_n];
 
vector<int> f(vector<int> vert, int col) {
    if (vert.empty()) {
        return {col == 0 ? inf : 0, col == 0 ? 0 : inf};
    }
 
    int siz = 0;
    for(int i : vert)
        siz += sz(dp[i][0]);
 
    vector<int> res(siz, inf);
    res[0] = 0;
 
    for(int v : vert) {
        int sz_v = sz(dp[v][0]);
        vector<int> new_res(siz, inf);
        for(int i = siz - sz_v;i >= 0;i--) {
            //if (res[i] == inf) continue;
            for(int j = 0;j < sz_v;j++) {
                new_res[i + j] = min(new_res[i + j], res[i] + min(dp[v][col][j], dp[v][1 - col][j] + 1));
            }
        }
        res = new_res;
    }
 
    return res;
}
 
void dfs(int v, int pr) {
    vector<int> temp;
    for(int i : gr[v]) {
        if (i == pr) continue;
        dfs(i, v);
        temp.emplace_back(i);
    }
 
    dp[v][0] = f(temp, 0);
    dp[v][1] = f(temp, 1);
}
 
void solve() {
    cin >> n;
 
    if (n == 2) {
        cout << 2;
        return;
    }
 
    for(int i = 0;i < n - 1;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        gr[v1].emplace_back(v2);
        gr[v2].emplace_back(v1);
    }
 
    int root = -1, cnt = 0;
    for(int i = n;i >= 1;i--) {
        if (sz(gr[i]) > 1) root = i;
        else cnt++;
    }
 
    dfs(root, -1);
    
    cout << min(dp[root][0][cnt / 2], dp[root][1][cnt / 2]);
}
 
 
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(3);
 
    solve();
}