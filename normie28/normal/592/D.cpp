#include <bits/stdc++.h>
using namespace std;
int n,m;
int h[150005];
bool mark[150005];
bool vis[150005];
vector<int> from[150005];
queue<int> q;
void dfs(int x,int last)
{
    int i;
    h[x] = h[last]+1;
    for(i=0;i<from[x].size();i++)
    {
        if(from[x][i]!=last) dfs(from[x][i],x);
    }
}
main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int i,x,y,ans,val,a;
    cin>>n>>m;
    for(i=0;i<n-1;i++)
    {
    	cin>>x>>y;
        from[x].push_back(y);
        from[y].push_back(x);
    }
    for(i=0;i<m;i++)
    {
    	cin>>x;
        mark[x] = true;
    }
 
    for(i=1;i<=n;i++) if(mark[i]) x = i;
    memset(h,0,sizeof(h));
    dfs(x,0);
 
    for(i=1;i<=n;i++) if(mark[i] && h[i]>h[x]) x = i;
    memset(h,0,sizeof(h));
    dfs(x,0);
 
    a = x;
    for(i=1;i<=n;i++)
    {
        if(mark[i] && h[i]>h[a]) a = i;
    }
    a = min(a,x);
 
    val = 0;
    for(i=1;i<=n;i++)
    {
        if(mark[i])
        {
            vis[i] = true;
            q.push(i);
            if(h[i]>val) val = h[i];
        }
    }
 
    ans = 0;
    while(!q.empty())
    {
        x = q.front(); q.pop();
        for(i=0;i<from[x].size();i++)
        {
            if(h[from[x][i]] > h[x]) continue;
            if(!vis[from[x][i]])
            {
                vis[from[x][i]] = true;
                q.push(from[x][i]);
            }
            ans++;
        }
    }
    cout<<a<<endl<<ans*2-val+1;
}