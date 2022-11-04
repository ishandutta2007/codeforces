#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 300010
#define M 600010
int n,m,rt,e;
int head[M],last[M],p[N],ord[M],ori[M],pre_ori[M];
bool flag,vis[N];
vector<int> vec;
void add(int x,int y,int o,int posi)
{
    head[++e]=y;
    ord[e]=o;
    pre_ori[e]=posi;
    last[e]=p[x];
    p[x]=e;
}
void dfs(int x,int pre)
{
    //cout<<x<<" "<<pre<<endl;
    vis[x]=true;
    for(int j=p[x]; j; j=last[j])
    {
        int y=head[j];
        if(y==pre || ori[ord[j]]+pre_ori[j]==0) continue;
        if(vis[y]) ori[ord[j]]=1;
        else
        {
            if(ori[ord[j]]==1) dfs(y,x);
            else
            {
                if(flag)
                {
                    ori[ord[j]]=pre_ori[j];
                    dfs(y,x);
                }
                else
                    ori[ord[j]]=-pre_ori[j];
            }

        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&rt);
    for(int i=1; i<=m; ++i)
    {
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);
        if(t==1) add(x,y,i,1),ori[i]=1;
        else add(x,y,i,1),add(y,x,i,-1),ori[i]=0,vec.push_back(i);
    }
    flag=true;
    dfs(rt,-1);
    int ans=0;
    for(int i=1; i<=n; ++i)
        ans+=vis[i],vis[i]=0;
    printf("%d\n",ans);
    for(auto &x:vec)
    {
        if(ori[x]==1) printf("+");
        else printf("-");
        ori[x]=0;
    }
    puts("");

    flag=false;
    dfs(rt,-1);
    ans=0;
    for(int i=1; i<=n; ++i)
        ans+=vis[i],vis[i]=0;
    printf("%d\n",ans);
    for(auto &x:vec)
    {
        if(ori[x]==1) printf("+");
        else printf("-");
        ori[x]=0;
    }
    puts("");
}