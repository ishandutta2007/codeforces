#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, k, tav[c], dist[c], sol[c];
vector<int> sz[c], s[c];
queue<pair<int, pair<int, int> > > q;
bool v[c];
void msdfs(int st) {
    for (int i=1; i<=n; i++) v[i]=0, tav[i]=0;
    while(q.size()) {
        int id=q.front().first, ert=q.front().second.first, sp=q.front().second.second;
        q.pop();
        if (!v[id]) {
            if (ert==1 && dist[id]==st-1) sp=1;
            if (ert<st || (ert==st && !sp)) {
                v[id]=1, tav[id]=ert;
                if (tav[id]<st) {
                    for (int x:sz[id]) {
                        if (!v[x]) {
                            q.push({x, {ert+1, sp}});
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    cin >> k;
    for (int i=0; i<k; i++) {
        int x; cin >> x;
        q.push({x, {0, 0}});
    }
    msdfs(c);
    for (int i=1; i<=n; i++) {
        dist[i]=tav[i];
        s[dist[i]].push_back(i);
    }
    for (int i=1; i<=n; i++) {
        if (s[i].size()>0) {
            for (int x:s[i]) {
                bool jo=1;
                for (int y:sz[x]) {
                    if (dist[y]>dist[x]) jo=0;
                }
                if (jo) q.push({x, {0, 0}});
            }
            if (q.size()>0) {
                msdfs(i);
                for (int j=1; j<=n; j++) {
                    if (v[j]) sol[j]=i;
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cout << sol[i] << " ";
    }
    cout << "\n";
    return 0;
}