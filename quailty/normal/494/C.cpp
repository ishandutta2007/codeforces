#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef double db;
const int MAXN=100005;
const int MAXQ=5005;
int a[MAXN];
struct node
{
    int l,r,m,v;
}s[MAXN<<2];
void build(int l,int r,int n)
{
    int m=(l+r)/2;
    s[n].l=l;
    s[n].r=r;
    s[n].m=m;
    if(r-l==1)
    {
        s[n].v=a[l];
        return;
    }
    build(l,m,n<<1);
    build(m,r,n<<1|1);
    s[n].v=max(s[n<<1].v,s[n<<1|1].v);
}
int query(int l,int r,int n)
{
    if(l==s[n].l && r==s[n].r)return s[n].v;
    if(r<=s[n].m)return query(l,r,n<<1);
    if(l>=s[n].m)return query(l,r,n<<1|1);
    return max(query(l,s[n].m,n<<1),query(s[n].m,r,n<<1|1));
}
int val[MAXQ],l[MAXQ],r[MAXQ],rk[MAXQ],in[MAXQ];
db p[MAXQ],dp[MAXQ][MAXQ];
bool cmp(int a,int b)
{
    return r[a]-l[a]>r[b]-l[b];
}
vector<int>e[MAXQ];
void dfs(int u,int &q)
{
    dp[u][0]=0;
    for(int i=1;i<=q+1;i++)dp[u][i]=1;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        dfs(v,q);
        if(val[u]>val[v])
        {
            for(int j=0;j<=q+1;j++)
            {
                db tmp=1;
                if(val[u]-val[v]+j<=q+1)tmp=dp[v][val[u]-val[v]+j];
                dp[u][j]*=tmp;
            }
        }
        else
        {
            for(int j=0;j<=q+1;j++)
            {
                db tmp=1;
                if(val[v]-val[u]+j<=q+1)tmp=dp[u][val[v]-val[u]+j];
                dp[v][j]*=tmp;
            }
            val[u]=val[v];
            for(int j=0;j<=q+1;j++)
                dp[u][j]=dp[v][j];
        }
    }
    for(int i=q+1;i>0;i--)
        dp[u][i]=(dp[u][i]*(1-p[u])+dp[u][i-1]*p[u]);
    dp[u][0]*=(1-p[u]);
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,n+1,1);
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d%lf",&l[i],&r[i],&p[i]);
        val[i]=query(l[i],r[i]+1,p[i]);
    }
    l[++q]=1,r[q]=n,val[q]=query(1,n+1,1),p[q]=0;
    for(int i=1;i<=q;i++)rk[i]=i;
    sort(rk+1,rk+q+1,cmp);
    for(int i=1;i<=q;i++)
        for(int j=i-1;j>0;j--)
            if(l[rk[i]]>=l[rk[j]] && r[rk[i]]<=r[rk[j]])
            {
                e[rk[j]].push_back(rk[i]);
                in[rk[i]]++;
                break;
            }
    int loc=q;
    for(int i=1;i<=q;i++)
        if(!in[i])loc=i;
    dfs(loc,q);
    db res=val[loc];
    for(int i=0;i<=q;i++)
        res+=i*(dp[loc][i+1]-dp[loc][i]);
    return 0*printf("%.10f",res);
}