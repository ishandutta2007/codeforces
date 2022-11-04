#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = (int) 1e5;

vector <int> g[MAXN + 1];

vector <int> sol[MAXN + 1];
bool vis[MAXN + 1];
int sz;

void dfs(int nod) {
    vis[nod] = 1;
    sol[sz].push_back(nod);
    for(auto it : g[nod]) {
        if(vis[it] == 0) {
            dfs(it);
        }
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x, y, nod;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int mx = 0, cnt = 0;
    for(i = 1; i <= n; i++) {
        if(g[i].size() > mx) {
            mx = g[i].size();
            nod = i;
        }
        if(g[i].size() > 2) {
            cnt++;
        }
    }
    if(cnt > 1) {
        cout << "No";
        return 0;
    }
    cout << "Yes" << "\n";
    vis[nod] = 1;
    for(auto it : g[nod]) {
        sz++;
        dfs(it);
    }
    cout << sz << "\n";
    for(i = 1; i <= sz; i++) {
        cout << nod << " " << sol[i].back() << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}