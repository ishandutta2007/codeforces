#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, m, pos[c], db[c], ert;
vector<int> sz[c];
vector<pair<int, int> > sol;
queue<int> q;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> m, ert=0, sol.clear();
        for (int i=1; i<=n; i++) pos[i]=0, db[i]=0, sz[i].clear();
        for (int i=1; i<=m; i++) {
            int x, a, b;
            cin >> x >> a >> b;
            sol.push_back({a, b});
            if (x==1) sz[a].push_back(b), db[b]++;
        }
        for (int i=1; i<=n; i++) if (!db[i]) q.push(i);
        while(q.size()) {
            int a=q.front();
            q.pop(), ert++, pos[a]=ert;
            for (int i=0; i<sz[a].size(); i++) {
                int x=sz[a][i];
                db[x]--;
                if (!db[x]) q.push(x);
            }
        }
        if (ert!=n) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i=0; i<m; i++) {
                int fi=sol[i].first, se=sol[i].second;
                if (pos[fi]>pos[se]) swap(fi, se);
                cout << fi << " " << se << "\n";
            }
        }
    }
    return 0;
}