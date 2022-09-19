#include <bits/stdc++.h>

using namespace std;
const long long c=300002;
long long n, m, k, hv[c], p[c], eler[c], visz[c], f[c], f2[c], si[c], fel[c], cnt=1, gy;
long long dp[c], vel[c], ert[c], o=0;
vector<long long> sz[c], s[c], sz2[c], s2[c], torol;
bool sp[c], v[c], v2[c], v3[c], rossz[c];
long long holvan(long long a) {
    if (!hv[a]) return a;
    long long x=holvan(hv[a]);
    hv[a]=x;
    return x;
}
void unio(long long a, long long b) {
    a=holvan(a), b=holvan(b);
    //cout << "unio " << a << " " << b << "\n";
    if (a!=b) {
        ert[a]+=ert[b], ert[b]=0;
        if (sp[b]) sp[a]=1;
        hv[b]=a;
    }
}
void dfs(long long a) {
    eler[a]=cnt, visz[a]=cnt, cnt++, v[a]=1;
    for (long long i=0; i<sz[a].size(); i++) {
        long long x=sz[a][i];
        if (!v[x]) {
            f[x]=a;
            dfs(x);
            visz[a]=min(visz[a], visz[x]);
            if (visz[x]<=eler[a]) unio(x, a);
        } else if (x!=f[a]) visz[a]=min(visz[a], eler[x]);
    }
}
void dfs2(long long a) {
    v2[a]=1; dp[a]=ert[a];
    for (long long i=0; i<sz2[a].size(); i++) {
        long long x=sz2[a][i], y=s2[a][i];
        if (!v2[x]) {
            f2[x]=a;
            dfs2(x);
            dp[a]+=max(o, dp[x]-y);
        } else fel[a]=y;
    }
}
void dfs3(long long a) {
    v3[a]=1;
    vel[a]=max(o, dp[f2[a]]+vel[f2[a]]-fel[a]-max(o, dp[a]-fel[a]));
    for (long long i=0; i<sz2[a].size(); i++) {
        long long x=sz2[a][i];
        if (!v3[x]) dfs3(x);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (long long i=1; i<=k; i++) {long long x; cin >> x; sp[x]=1;}
    for (long long i=1; i<=n; i++) cin >> ert[i];
    for (long long i=1; i<=m; i++) cin >> p[i];
    for (long long i=1; i<=m; i++) {
        long long x, y;
        cin >> x >> y;
        sz[x].push_back(y), sz[y].push_back(x), s[x].push_back(p[i]), s[y].push_back(p[i]);
    }
    dfs(1);
    for (long long i=1; i<=n; i++) {
        for (long long j=0; j<sz[i].size(); j++) {
            long long x=holvan(i), y=holvan(sz[i][j]);
            if (x!=y) sz2[x].push_back(y), s2[x].push_back(s[i][j]);
        }
    }
    for (long long i=1; i<=n; i++) {
        si[i]=sz2[i].size();
        if (holvan(i)!=i) rossz[i]=1;
        if (si[i]==1 && !sp[i]) torol.push_back(i);
    }
    while(torol.size()>0) {
        long long id=torol.back();
        //cout << "torol " << id << "\n";
        torol.pop_back(), rossz[id]=1;
        for (long long i=0; i<sz2[id].size(); i++) {
            long long x=sz2[id][i];
            if (!rossz[x]) {
                unio(x, id);
                si[x]--;
                if (!sp[x] && si[x]==1) torol.push_back(x);
            }
        }
    }
    for (long long i=1; i<=n; i++) if (!rossz[i]) gy=i;
    dfs2(gy), dfs3(gy);
    //for (long long i=1; i<=n; i++) cout << i << " " << dp[i] << " " << vel[i] << "\n";
    for (long long i=1; i<=n; i++) cout << dp[holvan(i)]+vel[holvan(i)] << " ";
    return 0;
}
/*
10 9 1
1
1 2 3 4 5 6 7 8 9 10
7 7 7 7 7 7 7 7 7
1 7 4 9 3 10 8 10 5 9 9 10 5 6 2 7 5 1
*/