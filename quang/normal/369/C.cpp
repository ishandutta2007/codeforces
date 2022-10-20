#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 100010;

int n;
vector < pair<int, int> > a[N];
vector <int> ans;
int sl[N];

void DFS(int u, int p, int need) {
    sl[u] = need - 1;
    for(int i = 0; i < (int)a[u].size(); i++) {
        int v = a[u][i].first, t = a[u][i].second;
        if(v != p) {
            DFS(v, u, t);
            sl[u] += sl[v];
        }
    }
    if(need == 2 && sl[u] == 1) ans.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int x ,y ,t;
        cin >> x >> y >> t;
        a[x].push_back(make_pair(y, t));
        a[y].push_back(make_pair(x, t));
    }
    DFS(1, 0, 1);
    cout << ans.size() << endl;
    for(int i = 0; i < (int)ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}