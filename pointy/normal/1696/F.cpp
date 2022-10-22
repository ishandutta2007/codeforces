// By: Little09
// Problem: CF1696F Tree Recovery
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1696F
// Memory Limit: 500 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")
#define lowbit(x) (x&(-x))

const int inf=1e9; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=105;
int n,m; 
int a[N][N][N],fa[N*N],siz[N*N];
int ex[N],ey[N],tot,dis[N][N];

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
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
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}
int find(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
inline int num(int x,int y)
{
	if (x>y) swap(x,y);
	return (x-1)*n+y;
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if (x==y) return;
	fa[x]=y;
	siz[y]+=siz[x];
}
void work()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			for (int k=1;k<=n;k++)
			{
				a[i][j][k]=readchar()-'0';
				a[j][i][k]=a[i][j][k];
			}
		}
	}
	for (int i=1;i<=n*n;i++) fa[i]=i,siz[i]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			for (int k=1;k<=n;k++)
			{
				if (a[i][j][k]==1)
				{
					if (i==k||j==k)
					{
						printNo;
						return;
					}
					merge(num(i,k),num(j,k));
				}
			}
		}
	}
	for (int i=1;i<=n*n;i++)
	{
		if (find(i)==i&&siz[i]==n-1)
		{
			tot=0;
			for (int j=1;j<=n*n;j++)
			{
				if (find(j)==i)
				{
					ex[++tot]=(j-1)/n+1;
					ey[tot]=(j-1)%n+1;
				}
			}
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=n;j++)
				{
					dis[i][j]=inf;
				}
				dis[i][i]=0;
			}
			for (int i=1;i<=tot;i++) 
			{
				dis[ex[i]][ey[i]]=1;
				dis[ey[i]][ex[i]]=1;
			}
			for (int k=1;k<=n;k++)
			{
				for (int i=1;i<=n;i++)
				{
					for (int j=1;j<=n;j++)
					{
						dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
					}
				}	
			}
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=n;j++)
				{
					if (dis[i][j]>=inf)
					{
						goto uuu;
					}
				}
			}
			for (int i=1;i<=n;i++)
			{
				for (int j=i+1;j<=n;j++)
				{
					for (int k=1;k<=n;k++)
					{
						bool u=(dis[i][k]==dis[j][k]);
						bool v=a[i][j][k];
						if (u!=v)
						{
							goto uuu;
						}
					}
				}
			}
			printYes;
			for (int i=1;i<=tot;i++)
			{
				printf("%d %d\n",ex[i],ey[i]);
			}
			return;
			uuu:;
		}
	}
	printNo;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}