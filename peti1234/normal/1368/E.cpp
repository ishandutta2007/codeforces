#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, m, bf[c], v[c], db;
bool vb[c];
vector<int> ki[c];
queue<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m, db=0;
        for (int i=1; i<=n; i++) v[i]=0, vb[i]=0, bf[i]=0, ki[i].clear();
        for (int i=1; i<=m; i++) {int a, b; cin >> a >> b, ki[a].push_back(b), bf[b]++;}
        for (int i=1; i<=n; i++) if (!bf[i]) q.push(i);
        while(q.size()>0) {
            int a=q.front();
            q.pop();
            if (!v[a]) v[a]=1;
            for (int i=0; i<ki[a].size(); i++) {
                int x=ki[a][i]; bf[x]--;
                if (!bf[x]) q.push(x);
                if (v[a]==1) vb[x]=1;
                if (v[a]==1 && vb[a]) v[x]=2;
            }
        }
        for (int i=1; i<=n; i++) if (v[i]==2) db++;
        cout << db << "\n";
        for (int i=1; i<=n; i++) if (v[i]==2) cout << i << " ";
        cout << "\n";
    }
    return 0;
}