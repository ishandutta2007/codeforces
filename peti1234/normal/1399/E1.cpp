#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long w, n, fel[c], l[c], f, sum, ans;
vector<long long> sz[c], s[c], e, k;
bool v[c];
void dfs(int a) {
    v[a]=true;
    if (a!=1 && sz[a].size()==1) l[a]++;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i], y=s[a][i];
        if (!v[x]) fel[x]=y, dfs(x), l[a]+=l[x];
    }
    sum+=fel[a]*l[a];
    while(fel[a]) {
        int x=fel[a]/2;
        e.push_back((fel[a]-x)*l[a]), fel[a]=x;
    }
}
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> f, sum=0, ans=0, e.clear();
        for (int i=1; i<=n; i++) l[i]=0, v[i]=0, sz[i].clear(), s[i].clear();
        for (int i=1; i<n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            sz[a].push_back(b), sz[b].push_back(a), s[a].push_back(c), s[b].push_back(c);
        }
        dfs(1), sum-=f;
        sort(e.rbegin(), e.rend());
        while(sum>0) sum-=e[ans], ans++;
        cout << ans << "\n";
    }
    return 0;
}