#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=2e5+10;
int a[M],b[M],n,m,sum,fa[M];

int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int a,int b){fa[find(a)]=find(b);}

struct edge
{
	int a,b,c;
}e[M];int cnt;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

bool cmp(edge a,edge b)
{
	return a.c>b.c;
}

signed main()
{
	m=read(),n=read();
	for (int i=1;i<=m;i++)a[i]=read();
	for (int i=1;i<=n;i++)b[i]=read();
	for (int i=1;i<=m;i++)
	{
		int s=read();
		for (int j=1;j<=s;j++)
		{
			int k=read();
			e[++cnt].a=k,e[cnt].b=i+n,e[cnt].c=a[i]+b[k];
			sum+=a[i]+b[k];
		}
	}
	for (int i=1;i<=n+m;i++)fa[i]=i;
	sort(e+1,e+1+cnt,cmp);
	for (int i=1;i<=cnt;i++)
	{
		if (find(e[i].a)==find(e[i].b))continue;
		merge(e[i].a,e[i].b),sum-=e[i].c;
	}
	cout<<sum;
	return 0;
}