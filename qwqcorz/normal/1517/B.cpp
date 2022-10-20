#include<bits/stdc++.h>
#define piir pair<int,int>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=105;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
piir b[N*N];
int a[N][N],id[N][N],p[N][N];
inline bool cmp(piir x,piir y)
{
	return a[x.fi][x.se]<a[y.fi][y.se];
}

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read(),m=read(),cnt=0;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) id[i][j]=0;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) a[i][j]=read(),b[++cnt]=mk(i,j);
		sort(b+1,b+1+n*m,cmp);
		for (int i=1;i<=m;i++) id[b[i].fi][b[i].se]=i;
		for (int i=1;i<=n;i++)
		{
			int cnt=0;
			for (int j=1;j<=m;j++)
			if (!id[i][j])
			{
				bool flag;
				do
				{
					cnt++;
					flag=0;
					for (int k=1;k<=m;k++) if (id[i][k]==cnt) flag=1;
				}while (flag);
				id[i][j]=cnt;
			}
			for (int j=1;j<=m;j++) p[i][j]=j;
			sort(p[i]+1,p[i]+1+m,[&](int x,int y){
				return id[i][x]<id[i][y];
			});
		}
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) print(a[i][p[i][j]],j%m?' ':'\n');
	}
	
	return 0;
}