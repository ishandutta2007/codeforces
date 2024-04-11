#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int w, n, m, n2, scc[c], si[c], be[c];
long long ans[c], sok=1e9;
vector<int> sz[c], rev[c], uj[c], sor;
bool v[c], v2[c], spec[c];
queue<int> q;
void dfs(int a) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
    sor.push_back(a);
}
void dfs2(int a) {
    v2[a]=true;
    si[scc[a]]++;
    for (auto x:rev[a]) {
        if (!v2[x]) {
            scc[x]=scc[a];
            dfs2(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        n2=n;
        for (int i=1; i<=m; i++) {
            int a, b;
            cin >> a >> b;
            if (a==b) {
                b=++n;
                rev[a].push_back(b), sz[b].push_back(a);
            }
            sz[a].push_back(b), rev[b].push_back(a);
        }
        for (int i=1; i<=n; i++) {
            if (!v[i]) {
                dfs(i);
            }
        }
        for (int i=n-1; i>=0; i--) {
            int x=sor[i];
            if (!v2[x]) {
                scc[x]=x;
                spec[x]=1;
                dfs2(x);
            }
        }
        for (int i=1; i<=n; i++) {
            for (auto x:sz[i]) {
                int a=scc[i], b=scc[x];
                if (a!=b) {
                    uj[a].push_back(b);
                    be[b]++;
                }
            }
        }
        for (int i=1; i<=n; i++) {
            if (spec[i] && !be[i]) {
                q.push(i);
            }
        }
        ans[scc[1]]=1;
        while (q.size()>0) {
            int a=q.front();
            q.pop();
            if (ans[a] && si[a]>1) {
                ans[a]=sok;
            }
            if (ans[a]>=sok) {
                ans[a]=sok;
            } else if (ans[a]>=2) {
                ans[a]=2;
            }
            for (auto x:uj[a]) {
                ans[x]+=ans[a];
                be[x]--;
                if (!be[x]) {
                    q.push(x);
                }
            }
        }
        //cout << "valasz............................................. ";
        for (int i=1; i<=n2; i++) {
            cout << (ans[scc[i]]==sok ? -1 : ans[scc[i]]) << " ";
        }
        cout << "\n";



        for (int i=1; i<=n; i++) {
            scc[i]=0, si[i]=0, be[i]=0, ans[i]=0, v[i]=0, v2[i]=0, spec[i]=0;
            sz[i].clear(), rev[i].clear(), uj[i].clear();
        }
        sor.clear();
    }
    return 0;
}