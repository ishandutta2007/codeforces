#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int inf=1e18;
const int M=2e5+10;
int n,m,k,id[M<<1];
int maxn[M],dd[M],del[M];
vector<int>e1,e2;

struct edge{int to,next,w;}e[M<<1];int cnt=1,head[M];
void add(int u,int to,int w){e[++cnt].to=to,e[cnt].w=w,e[cnt].next=head[u],head[u]=cnt;}
void add_edge(int u,int to,int w){add(u,to,w),add(to,u,w);}

struct node
{
	int a,b,w,id;
}a[M];
bool cmp(node a,node b){return a.w<b.w;}

int f[M];

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

void getmax(int u,int fa)
{
//	if (fa==1)cout<<u<<' ';
	for (int i=head[u];i;i=e[i].next)
	{
		int to=e[i].to;
		if (to==fa||del[i]||to==1)continue;
		if (e[i].w>=e[maxn[u]].w)maxn[to]=i;
		else maxn[to]=maxn[u];
		getmax(to,u);
	}
}

signed main()
{
	n=read(),m=read(),k=read();
	for (int i=1;i<=m;i++)
		a[i].a=read(),a[i].b=read(),a[i].w=read(),a[i].id=i;
	//puts("");
	for (int i=1;i<=n;i++)f[i]=i;
	sort(a+1,a+1+m,cmp);
	for (int i=1;i<=m;i++)
	{
		int u=find(a[i].a),v=find(a[i].b);
		if (u==v||u==1||v==1)continue;
		f[u]=v,add(a[i].a,a[i].b,a[i].w),add(a[i].b,a[i].a,a[i].w);
		e2.pb(a[i].id),id[cnt]=id[cnt-1]=a[i].id;
	}//puts("");
	for (int i=1;i<=m;i++)
	{
		if (a[i].a!=1&&a[i].b!=1)continue;
		int u=find(a[i].a),v=find(a[i].b);
		if (u==v)e1.pb(i);
		else e2.pb(a[i].id),k--,add(a[i].a,a[i].b,a[i].w),add(a[i].b,a[i].a,a[i].w),f[u]=v;
	}//puts("");
	if (k<0)return puts("-1"),0;
	for (int i=2;i<=n;i++)
		if (find(i)!=find(i-1))return puts("-1"),0;
//	k=1;

    for(int i=1; i<=k; ++i)
    {
        if(!e1.size()) return printf("-1"),0; 
        memset(maxn,0,sizeof(maxn));
        for(int j=head[1];j;j=e[j].next)getmax(e[j].to,1);
        int now=-1, ans=2147483647;
        for(int j=e1.size()-1; j>=0; --j) 
        {
            int p=e1[j],var=max(a[p].a, a[p].b);
            if(a[p].w-e[maxn[var]].w<ans)ans=a[p].w-e[maxn[var]].w,now=j;
        }
        int p=e1[now], var=max(a[p].a,a[p].b);
        add_edge(a[p].a, a[p].b, e[p].w); e2.pb(a[p].id); 
        dd[id[maxn[var]]]=1; del[maxn[var]]=del[maxn[var]^1]=1;
        e1.erase(e1.begin()+now);
    }
	cout<<n-1<<endl;
	for (int i=(int)e2.size()-1;i>=0;i--)
		if (!dd[e2[i]])
			cout<<e2[i]<<' ';
	return 0;
}