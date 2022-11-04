#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;

const int MAXN = (int) 1e5;

vector<int> g[MAXN + 1];
bool parity[MAXN + 1][2];
int mn = 1;

int dfs(int nod, int par) {
    int ans = (par != 0), sz = 0, cnt = 0;
    for(auto it : g[nod]) {
        if(it != par) {
            ans += dfs(it, nod);
            for(int p = 0; p < 2; p++) {
                parity[nod][p ^ 1] |= parity[it][p];
            }
            sz++;
            cnt += (g[it].size() == 1);
        }
    }
    if(sz == 0) {
        parity[nod][0] = 1;
    }
    if(parity[nod][0] && parity[nod][1]) {
        mn = 3;
    }
    if(cnt > 0) {
        ans -= (cnt - 1);
    }
    return ans;
}

int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    int root = 1;
    while((int)g[root].size() == 1) {
        root++;
    }

    int mx = dfs(root, 0);

    cout << mn << " " << mx;


    return 0;
}