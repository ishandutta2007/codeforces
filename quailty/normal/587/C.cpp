#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
const int MAXN=100005;
struct Edge
{
    int to,next;
}edge[MAXN<<1];
int head[MAXN],tot;
int top[MAXN];
int fa[MAXN];
int deep[MAXN];
int num[MAXN];
int p[MAXN];
int fp[MAXN];
int son[MAXN];
int pos;
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
    pos=1;
    memset(son,-1,sizeof(son));
}
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void dfs1(int u,int pre,int d)
{
    deep[u]=d;
    fa[u]=pre;
    num[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v!=pre)
        {
            dfs1(v,u,d+1);
            num[u]+=num[v];
            if(son[u]==-1 || num[v]>num[son[u]])
                son[u]=v;
        }
    }
}
void dfs2(int u,int sp)
{
    top[u]=sp;
    p[u]=pos++;
    fp[p[u]]=u;
    if(son[u]==-1)return;
    dfs2(son[u],sp);
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v!=son[u] && v!=fa[u])
            dfs2(v,v);
    }
}
struct node
{
    int l,r,m;
    priority_queue<int>c;
}s[MAXN<<2];
void build(int l,int r,int n)
{
    int m=(l+r)>>1;
    s[n].l=l;
    s[n].r=r;
    s[n].m=m;
    while(!s[n].c.empty())s[n].c.pop();
    if(r-l==1)return;
    build(l,m,n<<1);
    build(m,r,n<<1|1);
}
void update(int p,int v,int n)
{
    s[n].c.push(v);
    while(s[n].c.size()>10)s[n].c.pop();
    if(s[n].l==p && s[n].r==p+1)return;
    if(p<s[n].m)update(p,v,n<<1);
    else update(p,v,n<<1|1);
}
priority_queue<int> query(int l,int r,int n)
{
    if(s[n].l==l && s[n].r==r)return s[n].c;
    if(r<=s[n].m)return query(l,r,n<<1);
    if(l>=s[n].m)return query(l,r,n<<1|1);
    priority_queue<int> q1,q2;
    q1=query(l,s[n].m,n<<1);
    q2=query(s[n].m,r,n<<1|1);
    while(!q2.empty())
    {
        q1.push(q2.top());
        q2.pop();
    }
    while(q1.size()>10)q1.pop();
    return q1;
}
void solve(int u,int v,int a)
{
    priority_queue<int>res;
    while(!res.empty())res.pop();
    int f1=top[u],f2=top[v];
    while(f1!=f2)
    {
        if(deep[f1]<deep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        }
        priority_queue<int> qur=query(p[f1],p[u]+1,1);
        while(!qur.empty())
        {
            res.push(qur.top());
            qur.pop();
        }
        while(res.size()>a)res.pop();
        u=fa[f1];
        f1=top[u];
    }
    if(deep[u]>deep[v])swap(u,v);
    priority_queue<int> qur=query(p[u],p[v]+1,1);
    while(!qur.empty())
    {
        res.push(qur.top());
        qur.pop();
    }
    while(res.size()>a)res.pop();
    printf("%d",res.size());
    stack<int>st;
    while(!res.empty())
    {
        st.push(res.top());
        res.pop();
    }
    while(!st.empty())
    {
        printf(" %d",st.top());
        st.pop();
    }
    printf("\n");
}
int get_int()
{
    char ch;
    while((ch=getchar())<'0' || ch>'9');
    int res=ch-'0';
    while((ch=getchar())>='0' && ch<='9')res=res*10+ch-'0';
    return res;
}
int main()
{
    int n=get_int(),m=get_int(),q=get_int();
    //scanf("%d%d%d",&n,&m,&q);
    init();
    for(int i=1;i<n;i++)
    {
        int u=get_int(),v=get_int();
        //scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    dfs1(1,0,0);
    dfs2(1,1);
    build(1,n+1,1);
    for(int i=1;i<=m;i++)
    {
        int in=get_int();
        //scanf("%d",&in);
        update(p[in],i,1);
    }
    while(q--)
    {
        int u=get_int(),v=get_int(),a=get_int();
        //scanf("%d%d%d",&u,&v,&a);
        solve(u,v,a);
    }
    return 0;
}