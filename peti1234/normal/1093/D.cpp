#include <bits/stdc++.h>

using namespace std;
long long mod=998244353;
vector<int> sz[300001];
int n, m;
bool v[300001];
long long x, y;
long long h[300001];
long long t[300001];
long long ans=1;
int u;
long long bfs(int a)
{
    x=0, y=0;
    queue<int> q;
    q.push({a});
    h[a]=1;
    while(q.size()>0) {
        int f=q.front();
        if (h[f]==1) {
            x++;
        } else {
            y++;
        }
        v[f]=true;
        q.pop();
        for (int i=0; i<sz[f].size(); i++) {
            int b=sz[f][i];
            if (v[b] && h[f]==h[b]) {
                return 0;
            }
            if (!v[b]) {
                if (h[f]==1) {
                    h[b]=0;
                } else {
                    h[b]=1;
                }
                q.push(b);
                v[b]=true;
            }
        }
    }
    long long c=t[x]%mod;
    c+=t[y]%mod;
    c%=mod;
    return c;
}
int main()
{
    cin >> u;
    t[0]=1;
    for (int i=1; i<=300000; i++) {
        t[i]=t[i-1]*2;
        t[i]%=mod;
    }
    for (int i=1; i<=u; i++) {
        int n, m;
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            v[i]=false;
            h[i]=-1;
            sz[i].clear();
        }
        for (int i=1; i<=m; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b);
            sz[b].push_back(a);
        }
        for (int i=1; i<=n; i++) {
            if (!v[i]) {
                ans*=bfs(i);
                ans%=mod;
            }
        }
        cout << ans << endl;
        ans=1;
    }
    return 0;
}