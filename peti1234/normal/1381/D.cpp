#include <bits/stdc++.h>

using namespace std;
const int c=100002;
#define rep for (int i=1; i<=n; i++)
int w, n, p1, p2, ke, ve, tav, mki, mini, dist[c], t[c], tcs[c], ot[c], szint[c], maxle[c], f[c], hossz;
bool v[c], fo[c], kigyo[c], l;
vector<int> sz[c];
void dfs(int a) {
    v[a]=true;
    int te=0, tm=0, cse=a, csm=a;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            dfs(x);
            if (t[x]+1>tm) tm=t[x]+1, csm=tcs[x];
            if (tm>te) swap(tm, te), swap(cse, csm);
        }
    }
    if (te+tm>tav) tav=te+tm, p1=cse, p2=csm;
    t[a]=te, tcs[a]=cse;
}
void dfs2(int a) {
    v[a]=true, dist[a]+=szint[a];
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) szint[x]=szint[a]+1, dfs2(x);
    }
}
void dfs3(int a) {
    v[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x] && (dist[x]>dist[a] || !kigyo[x])) {
            f[x]=a;
            dfs3(x);
            maxle[a]=max(maxle[a], maxle[x]+1);
        }
    }
}
void pont(int a, int b) {
    rep v[i]=0, szint[i]=0;
    dfs2(a);
    rep v[i]=0, szint[i]=0;
    dfs2(b);
}
int klep(int fel) {
    while(fel && f[ke]) ke=f[ke], fel--;
    return maxle[ke]+fel;
}
int vlep(int fel) {
    while(fel && f[ve]) ve=f[ve], fel--;
    return maxle[ve]+fel;
}
bool ford() {
    int ell=maxle[ve], eld=ell, a;
    while(true) {
        a=klep(eld);
        if (a>=hossz) return true;
        if (a<=ell) return false;
        eld=a-ell, ell=a, a=vlep(eld);
        if (a>=hossz) return true;
        if (a<=ell) return false;
        eld=a-ell, ell=a;
    }
}
int main()
{
    cin >> w;
    for (int i=1; i<=w; i++) {
        cin >> n >> ke >> ve;
        p1=0, p2=0, tav=0, mki=0, mini=c, hossz=0, l=0;
        rep dist[i]=0, t[i]=0, tcs[i]=0, ot[i]=0, szint[i]=0, maxle[i]=0, f[i]=0, v[i]=0, fo[i]=0, kigyo[i]=0, sz[i].clear();
        for (int i=1; i<n; i++) {
            int a, b; cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        pont(ke, ve), hossz=dist[ke];
        rep kigyo[i]=(dist[i]==hossz), v[i]=0, dist[i]=0;
        dfs(1);
        pont(p1, p2);
        rep {
            fo[i]=(dist[i]==tav), dist[i]=(dist[i]-tav)/2, v[i]=0;
            mki=max(mki, dist[i]);
            if (kigyo[i]) mini=min(mini, dist[i]);
        }
        rep if (kigyo[i] && dist[i]==mini) dfs3(i);
        l=ford();
        if (l && mki>=hossz) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}