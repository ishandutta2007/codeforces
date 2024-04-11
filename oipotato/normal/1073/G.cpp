#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
#include<stack>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
const int N=200010;
namespace SAM
{
    const int S=26;
    int tot=1,last=1,pre[N<<1],son[N<<1][S],ml[N<<1];
    int extend(int w){
        int p=++tot,x=last,r,q;
        for(ml[last=p]=ml[x]+1;x&&!son[x][w];x=pre[x])son[x][w]=p;
        if(!x)pre[p]=1;
        else if(ml[x]+1==ml[q=son[x][w]])pre[p]=q;
        else{
            pre[r=++tot]=pre[q];memcpy(son[r],son[q],sizeof son[r]);
            ml[r]=ml[x]+1;pre[p]=pre[q]=r;
            for(;x&&son[x][w]==q;x=pre[x])son[x][w]=r;
        }
        return p;
    }
}
vector<int>g[N<<1],G[N<<1];
int par[20][N<<1],dep[N<<1],dfn[N<<1],tot,a[N],b[N],id[N],c[N<<2],x[N<<1],y[N<<1],n,q;
long long ans;
char s[N];
void dfs(int p)
{
    dfn[p]=++tot;
    rep(i,17)par[i][p]=par[i-1][par[i-1][p]];
    for(auto i:g[p]){dep[i]=dep[p]+1;par[0][i]=p;dfs(i);}
}
int lca(int x,int y)
{
    if(dep[x]>dep[y])swap(x,y);
    if(dep[y]>dep[x])for(int i=17;i>=0;i--)if(dep[par[i][y]]>=dep[x])y=par[i][y];
    if(x==y)return x;
    for(int i=17;i>=0;i--)if(par[i][x]!=par[i][y])x=par[i][x],y=par[i][y];
    return par[0][x];
}
bool cmp(int x, int y) {return dfn[x] < dfn[y];}
stack<int> stk;
void addedge(int x,int y){G[x].pb(y);}
int solve(int a[],int k)
{
    sort(a, a + k, cmp);
    int m = k;
    for (int j = 1; j < m; ++j)
        a[k++] = lca(a[j - 1], a[j]);
    sort(a, a + k, cmp);
    k = unique(a, a + k) - a;
    stk.push(a[0]);
    for (int j = 1; j < k; ++j) {
        int u = lca(stk.top(), a[j]);
        while (dep[stk.top()] > dep[u]) stk.pop();
        assert(stk.top() == u);
        stk.push(a[j]);
        addedge(u, a[j]);
    }
    for(;!stk.empty();stk.pop());
    return k;
}
void work(int p)
{
    long long C=0;
    for(auto i:G[p])
    {
        work(i);
        C-=1ll*x[i]*y[i];
        x[p]+=x[i];y[p]+=y[i];
    }
    C+=1ll*x[p]*y[p];
    //printf("%d %d %d %d %lld\n",p,x[p],y[p],SAM::ml[p],C);
    ans+=C*SAM::ml[p];
}
int main()
{
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    for(int i=n;i;i--)id[i]=SAM::extend(s[i]-'a');
    rep(i,SAM::tot)if(i!=1)g[SAM::pre[i]].pb(i);//,printf("%d %d\n",i,SAM::pre[i]);
    dfs(dep[1]=1);
    rep(i,q)
    {
        int n1,n2;
        scanf("%d%d",&n1,&n2);
        rep(j,n1)scanf("%d",&a[j]),a[j]=id[a[j]],c[j-1]=a[j],x[a[j]]=1;
        rep(j,n2)scanf("%d",&b[j]),b[j]=id[b[j]],c[j+n1-1]=b[j],y[b[j]]=1;
        int len=solve(c,n1+n2);
        ans=0;
        //rep(j,len)printf("%d%c",c[j-1]," \n"[j==len]);
        work(c[0]);
        rep(j,len)x[c[j-1]]=y[c[j-1]]=0,G[c[j-1]].clear();
        printf("%lld\n",ans);
    }
	return 0;
}