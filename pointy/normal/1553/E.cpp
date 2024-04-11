//By Little09

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=300005;
int n,m,T; 
int a[N],tmp[N],ans[N],cnt;

int fa[N],rans[N],tot;
int find(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 

void check(int x)
{
	for (int i=1;i<=n;i++) fa[i]=i;
	int res=0;
	for (int i=1;i<=n;i++)
	{
		int u=i-x;
		if (u<=0) u+=n;
		int x1=find(u),y1=find(a[i]);
		if (x1==y1) res++;
		else fa[x1]=y1;
	}
	if (m>=n-res) rans[++tot]=x;
	return;
}

void work()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=0;i<=n;i++) tmp[i]=ans[i]=rans[i]=0;
	cnt=0;
	for (int i=1;i<=n;i++)
	{
		int u;
		if (a[i]<=i) u=i-a[i];
		else u=i+n-a[i];
		tmp[u]++;
	}
	for (int i=0;i<=n;i++)
	{
		if (tmp[i]>=n-m*2) ans[++cnt]=i;
	}
	tot=0;
	for (int i=1;i<=cnt;i++) check(ans[i]);
	cout << tot << " ";
	for (int i=1;i<=tot;i++) printf("%d ",rans[i]);
	cout << endl;
	return;
}

int main()
{
	T=read();
	while (T--)
	{
		work();
	}
	return 0;
}

//1 2 3 4 5 6
//2 6 5 1 3 4