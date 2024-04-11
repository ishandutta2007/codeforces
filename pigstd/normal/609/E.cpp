#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=2*1e5+10;

int n,m,sum,cnt;
int f[M];

struct node
{
	int a,b,c;
}a[M],c[M],kkkk[M];

struct NODE
{
	int to,next,w;
}b[M*2];
int head[M],sumb;

int fa[M][30],maxn[M][30],de[M];

int find(int x)
{
	if (x==f[x])
		return x;
	return f[x]=find(f[x]);
}

bool cmp(node a,node b)
{
	return a.c<b.c;
}

void add(int u,int to,int w)
{
	b[++sumb].to=to,b[sumb].w=w,b[sumb].next=head[u],head[u]=sumb;
}

void dfs(int k,int fat,int w)
{
	de[k]=de[fat]+1,fa[k][0]=fat,maxn[k][0]=w;
	for (int i=1;i<=25;i++)
		fa[k][i]=fa[fa[k][i-1]][i-1],maxn[k][i]=max(maxn[k][i-1],maxn[fa[k][i-1]][i-1]);
	for (int i=head[k];i;i=b[i].next)
		if (b[i].to!=fat)
			dfs(b[i].to,k,b[i].w);
}

int LCA(int a,int b)//a,b
{
	int kkk=0;
	if (de[a]>de[b])
		swap(a,b);
	for (int i=25;i>=0;i--)
		if (de[fa[b][i]]>=de[a])
			kkk=max(kkk,maxn[b][i]),b=fa[b][i];
	if (a==b)return kkk;
	for (int i=25;i>=0;i--)
		if (fa[a][i]!=fa[b][i])
			kkk=max(kkk,max(maxn[b][i],maxn[a][i])),a=fa[a][i],b=fa[b][i];
	return max(kkk,max(maxn[b][0],maxn[a][0]));
} 

signed main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		f[i]=i;
	for (int i=1;i<=m;i++)
		cin>>a[i].a>>a[i].b>>a[i].c,kkkk[i]=a[i];
	sort(a+1,a+1+m,cmp);
	for (int i=1;i<=m&&cnt<n;i++)
	{
		int pa=find(a[i].a),pb=find(a[i].b);
		if (pa!=pb)
			f[pa]=pb,sum+=a[i].c,c[++cnt]=a[i],add(c[cnt].a,c[cnt].b,c[cnt].c),add(c[cnt].b,c[cnt].a,c[cnt].c);
	}//sum=
	dfs(1,0,0);
	for (int i=1;i<=m;i++)
	 	cout<<sum+kkkk[i].c-LCA(kkkk[i].a,kkkk[i].b)<<endl;
	return 0;
}