#include <bits/stdc++.h>
using namespace std;
vector<int> g[200007];
int sp[200007];
int d[2][200007],n;
pair<int,int> p[200007];
void bfs(int s,int k)
{
    for(int i=1;i<=n;i++) d[k][i]=-1;
    d[k][s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++) if(d[k][g[u][i]]==-1)
        {
            d[k][g[u][i]]=d[k][u]+1;
            q.push(g[u][i]);
        }
    }
}
int main()
{
    int m,k;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++) cin>>sp[i];
    for(int i=0;i<m;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    bfs(1,0); bfs(n,1);
    int res=0,mxa=-1;
    for(int i=0;i<k;i++) p[i]={d[0][sp[i]]-d[1][sp[i]],d[0][sp[i]]};
    sort(p,p+k);
    for(int i=0;i<k;i++)
    {
        if(i!=0) res=max(res,mxa+p[i].second-p[i].first+1);
        mxa=max(mxa,p[i].second);
    }
    cout<<min(d[0][n],res);
}