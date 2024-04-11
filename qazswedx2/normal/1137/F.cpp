#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
    int v,nxt;
}e[5000005];
int sum[1000005],h[1000005],t=0,cnt;
int n,m;
void add(int u,int v)
{
    e[++t].v=v;
    e[t].nxt=h[u];
    h[u]=t;
}
int lowbit(int x)
{
    return x&-x;
}
void modify(int x,int v)
{
    for(int i=x;i<=n+m;i+=lowbit(i))
        sum[i]+=v;
}
int query(int x)
{
    int ans=0;
    for(int i=x;i;i-=lowbit(i))
        ans+=sum[i];
    return ans;
}
int ch[1000005][2],rev[1000005],c[1000005],f[1000005],size[1000005];
bool nroot(int x)
{
    return ch[f[x]][0]==x||ch[f[x]][1]==x;
}
void pushup(int x)
{
    size[x]=size[ch[x][0]]+size[ch[x][1]]+1;
}
void pushr(int x)
{
    swap(ch[x][0],ch[x][1]);
    rev[x]^=1;
}
void pushdown(int x)
{
    if(rev[x])
    {
        if(ch[x][0]) pushr(ch[x][0]);
        if(ch[x][1]) pushr(ch[x][1]);
        rev[x]=0;
    }
    if(ch[x][0]) c[ch[x][0]]=c[x];
    if(ch[x][1]) c[ch[x][1]]=c[x];
}
void pushall(int x)
{
    if(nroot(x)) pushall(f[x]);
    pushdown(x);
}
void rotate(int x)
{
    int y=f[x],z=f[y],k=ch[y][1]==x,r=ch[x][!k];
    if(nroot(y)) ch[z][ch[z][1]==y]=x;
    ch[x][!k]=y;
    ch[y][k]=r;
    f[r]=y;
    f[y]=x;
    f[x]=z;
    pushup(y);
    pushup(x);
}
void splay(int x)
{
    pushall(x);
    while(nroot(x))
    {
        int y=f[x],z=f[y];
        if(nroot(y)) rotate((ch[y][1]==x)^(ch[z][1]==y)?x:y);
        rotate(x);
    }
}
void access(int x)
{
    for(int y=0;x;y=x,x=f[x])
    {
        splay(x);
        ch[x][1]=0;
        pushup(x);
        modify(c[x],-size[x]);
        modify(cnt,size[x]);
        ch[x][1]=y;
        pushup(x);
    }
}
void makeroot(int x)
{
    cnt++;
    access(x);
    splay(x);
    pushr(x);
    c[x]=cnt;
}
int getans(int x)
{
    splay(x);
    return query(c[x])-size[ch[x][0]];
}
void dfs(int u,int fa)
{
    c[u]=u;
    f[u]=fa;
    size[u]=1;
    for(int i=h[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==fa) continue;
        dfs(v,u);
        if(c[u]<c[v])
        {
            c[u]=c[v];
            ch[u][1]=v;
            pushup(u);
        }
    }
    modify(c[u],1);
}
void print()
{
	for(int i=1;i<=n;i++)
		printf("i=%d,f=%d,size=%d,ch=%d,%d,rev=%d,c=%d\n",i,
				f[i],size[i],ch[i][0],ch[i][1],rev[i],c[i]);
}
char s[100005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    cnt=n;
    dfs(n,0);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%s",s);
        if(s[0]=='u')
        {
            scanf("%d",&x);
            makeroot(x);
        }
        if(s[0]=='w')
        {
            scanf("%d",&x);
            printf("%d\n",getans(x));
            //printf("c=%d,ans=%d\n",c[x],query(c[x]));
        }
        if(s[0]=='c')
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",getans(x)>getans(y)?y:x);
        }
        //print();
    }
    return 0;
}