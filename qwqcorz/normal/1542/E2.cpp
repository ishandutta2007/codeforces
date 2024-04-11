#include<bits/stdc++.h>
using namespace std;
const int N=505;

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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int F[2][N*N*2],G[2][N*N*2],fact[N],C[N][N],n,p,ans=0;
void add(int &x,int y) {x+=y;if (x>=p) x-=p;}
int &f(int i,int j) {return F[i][j+N*N];}
int &g(int i,int j) {return G[i][j+N*N];}
void ysgsf(int t,int n) {for (int i=-n;i<=n;i++) add(f(t,i),f(t,i-1));}
void ysgsg(int t,int n) {for (int i=-n;i<=n;i++) add(g(t,i),g(t,i-1));}
int sumf(int t,int l,int r) {return (f(t,r)-f(t,l-1)+p)%p;}
int sumg(int t,int l,int r) {return (g(t,r)-g(t,l-1)+p)%p;}

signed main()
{
	n=read(),p=read();
	for (int i=fact[0]=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
	for (int i=C[0][0]=1;i<=n;i++)
	for (int j=C[i][0]=1;j<=n;j++)
	C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	f(0,0)=1;
	for (int i=1,t=1;i<=n;i++,t^=1)
	{
		memset(F[t],0,sizeof(F[t]));
		memset(G[t],0,sizeof(G[t]));
		int m=i*i;
		ysgsf(!t,m+i);
		for (int j=1;j<i;j++)
		for (int k=j+1;k<=i;k++)
		add(ans,1LL*sumf(!t,k-j+1,m)*fact[n-i]%p*C[n][n-i]%p);
		
		for (int j=-m;j<=m;j++) g(t,j)=sumf(!t,j-i+1,j);
		ysgsg(t,m+i);
		for (int j=-m;j<=m;j++) f(t,j)=sumg(t,j,j+i-1);
	}
	print(ans);
	
	return 0;
}