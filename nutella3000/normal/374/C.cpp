#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int n,m;
vector<vector<vector<int>>> gr;
vector<vector<int>> used;
vector<vector<int>> ans;
int xr[] {-1,0,0,1};
int yr[] {0,-1,1,0};
bool u = false;
void dfs(int x,int y) {
    if (used[x][y] == 2) {
        u = true;
    }
    if (used[x][y] != 0) return;
    used[x][y] = 2;
    int a = 0;
    for(int i : gr[x][y]) {
        dfs(xr[i] + x,yr[i] + y);
        a = max(a,ans[xr[i] + x][yr[i] + y]);
    }
    used[x][y] = 1;
    ans[x][y] = a + 1;
}
vector<string> s;
bool check(int i,int j,int x,int y) {
    if (s[i][j] == 'D' && s[x][y] == 'I') return true;
    if (s[i][j] == 'I' && s[x][y] == 'M') return true;
    if (s[i][j] == 'M' && s[x][y] == 'A') return true;
    if (s[i][j] == 'A' && s[x][y] == 'D') return true;
    return false;
}
int main() {
    cin.tie();
    cout.tie();
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    s.resize(n);
    gr.resize(n);
    used.resize(n);
    ans.resize(n);
    for(int i = 0;i < n;i++) {
        cin >> s[i];
        gr[i].resize(m);
        ans[i].resize(m,0);
        used[i].resize(m,false);
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            for(int k = 0;k < 4;k++) {
                int x = xr[k] + i;
                int y = yr[k] + j;
                if (x >= 0 && x < n && y < m && y >= 0 && check(i,j,x,y)) gr[i][j].push_back(k);
            }
        }
    }
    int mx = -1123123;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if (!used[i][j] && s[i][j] == 'D') {
                dfs(i, j);
            }
        }
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            mx = max(mx,ans[i][j] / 4);
        }
    }
    if (u) cout << "Poor Inna!";
    else if (mx == 0) cout << "Poor Dima!";
    else cout << mx;
}