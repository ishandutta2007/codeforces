#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}
int n,m,p,f[N][N],g[N][N],C[N][N],h[N],t[N],tmp[N][N],F[N][N],G[N][N];
void add(int &x,int y){x+=y;if (x>=p) x-=p;}
void ysgs(int n)
{
	for (int i=1;i<=n;i++)
	for (int j=1;j<=i;j++)
	for (int k=1;k<=i;k++)
	if (j!=k) add(tmp[i][j],abs(j-k));
	for (int i=C[0][0]=1;i<=n;i++)
	for (int j=C[i][0]=1;j<=i;j++)
	C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
}

signed main()
{
	n=read(),m=read(),p=read();
	ysgs(n);
	h[0]=0,t[0]=1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=i;j++)
		add(h[i],((1LL*h[j-1]*t[i-j]+1LL*t[j-1]*h[i-j])%p*C[i-1][j-1]%p*(i+1)+1LL*t[j-1]*t[i-j]%p*C[i-1][j-1]%p*tmp[i][j])%p),
		add(t[i],1LL*t[j-1]*t[i-j]%p*C[i-1][j-1]%p*(i+1)%p);
	F[0][0]=1;
	for (int i=0;i<=n;i++) G[i][0]=1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=i;j++)
	{
		F[i][j]=t[j];
		f[i][j]=h[j];
		for (int k=1;k<j;k++)
			add(f[i][j],(1LL*g[i-k-1][j-k]*t[k]%p*C[j][k]+1LL*G[i-k-1][j-k]*h[k]%p*C[j][k])%p),
			add(F[i][j],1LL*G[i-k-1][j-k]*t[k]%p*C[j][k]%p);
		g[i][j]=(g[i-1][j]+f[i][j])%p;
		G[i][j]=(G[i-1][j]+F[i][j])%p;
	}
	print(g[n][m]);
	
	return 0;
}