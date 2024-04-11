#include <bits/stdc++.h>
#define MAXN 300007
#define MAXL 30
using namespace std;
int a[MAXN],b[MAXN],val[MAXN],p[MAXN],sk[MAXN];
bool vi[MAXN];
set<int> s;
set<int>::iterator it;
vector<int> z;
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    vi[x]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        z.clear();
        for(it = s.lower_bound(u-a[u]); it != s.end() && *it <= u; it++)
        {
            int v=*it;
            z.push_back(v);
            int fol=val[v];
            if(vi[fol]) continue;
            vi[fol]=true;
            q.push(fol);
            sk[fol]=v; p[fol]=u;
        }
        for(int i=0;i<z.size();i++) s.erase(z[i]);
    }
}
int main()
{
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++) val[i]=i+b[i];
    for(int i=0;i<=n;i++) s.insert(i);
    bfs(n);
    if(!vi[0]) {printf("-1"); return 0;}
    vector<int> sol;
    int k=0;
    while(k!=n)
    {
        sol.push_back(sk[k]);
        k=p[k];
    }
    reverse(sol.begin(),sol.end());
    printf("%d\n",sol.size());
    for(int i=0;i<sol.size();i++) printf("%d ",sol[i]);
}