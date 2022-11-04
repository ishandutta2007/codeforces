#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 125

using namespace std;

const int MAXN = (int) 2e5;

vector <int> g[MAXN + 1];

set <int> mst;
set <int> :: iterator it;

bool viz[MAXN + 1];

int cnt;

void dfs(int nod) {
    vector <int> clr;
    viz[nod] = 1;
    cnt++;
    it = mst.begin();
    for(auto itr : g[nod]) {
        while(it != mst.end() && *it < itr) {
            clr.push_back(*it);
            it++;
        }
        if(*it == itr)
            it++;
    }
    for(auto itr : clr) {
        it = mst.find(itr);
        if(it != mst.end())
            mst.erase(it);
    }
    for(auto itr : clr) {
        if(viz[itr] == 0)
            dfs(itr);
    }
}

vector <int> sol;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, x, y;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(i = 1; i <= n; i++) {
        mst.insert(i);
        sort(g[i].begin(), g[i].end());
        g[i].push_back(n + 1);
    }
    for(i = 1; i <= n; i++) {
        if(viz[i] == 0) {
            cnt = 0;
            mst.erase(mst.find(i));
            dfs(i);
            sol.push_back(cnt);
        }
    }
    sort(sol.begin(), sol.end());
    cout << sol.size() << "\n";
    for(auto it : sol) {
        cout << it << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}