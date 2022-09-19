#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long w, n, fel[c], p[c], l[c], f, sum, p1, p2, ans, es, ks;
vector<long long> sz[c], s[c], t[c], e, k;
bool v[c];
void dfs(int a) {
    v[a]=true;
    if (a!=1 && sz[a].size()==1) l[a]++;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i], y=s[a][i], z=t[a][i];
        if (!v[x]) fel[x]=y, p[x]=z, dfs(x), l[a]+=l[x];
    }
    sum+=fel[a]*l[a];
    while(fel[a]) {
        int x=fel[a]/2;
        if (p[a]==1) e.push_back((fel[a]-x)*l[a]);
        else k.push_back((fel[a]-x)*l[a]);
        fel[a]=x;
    }
}
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> f, sum=0, p1=0, p2=0, ans=0, e.clear(), k.clear();
        for (int i=1; i<=n; i++) l[i]=0, v[i]=0, p[i]=0, sz[i].clear(), s[i].clear(), t[i].clear();
        for (int i=1; i<n; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            sz[a].push_back(b), sz[b].push_back(a), s[a].push_back(c), t[a].push_back(d), s[b].push_back(c), t[b].push_back(d);
        }
        dfs(1), sum-=f;
        sort(e.rbegin(), e.rend()), sort(k.rbegin(), k.rend()), es=e.size(), ks=k.size();
        while(sum>0 && p1<es) sum-=e[p1], p1++;
        while(sum>0 && p2<ks) sum-=k[p2], p2++;
        ans=p1+2*p2;
        while(p1) {
            p1--, sum+=e[p1];
            while(sum>0 && p2<ks) sum-=k[p2], p2++;
            if (sum<=0) ans=min(ans, p1+2*p2);
        }
        cout << ans << "\n";
    }
    return 0;
}