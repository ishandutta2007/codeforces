#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int K=10;
const long long p=998244353;

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
inline void add(int &x,int y)
{
	x+=y;
	if (x>=p) x-=p;
}
int f[N],g[N],inv[N];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read()/2,k=read(),ans=1,Max=0;
	for (int i=1;i<=k;i++) f[read()]=1;
	if (!f[0])
	for (int i=0;i<=9;i++)
	if (f[i])
	{
		for (int j=i;j<=9;j++) f[j-i]=f[j],f[j]=0;
		break;
	}
	g[0]=1;
	inv[0]=1;
	for (int i=1;i<=9;i++) if (f[i]) Max=i;
	for (int i=1;i<=n*Max;i++)
	{
		inv[i]=i>1?(p-p/i)*inv[p%i]%p:1;
		g[i]=1LL*n*g[0]%p*f[i]%p;
		for (int j=i-1;j>=1;j--)
		{
			if (i-j>9) break;
			add(g[i],1LL*inv[i]*g[j]%p*f[i-j]%p*((1LL*n*i%p-1LL*n*j%p-1LL*j+p+p)%p)%p);
		}
		add(ans,1LL*g[i]*g[i]%p);
	}
	print(ans);

	return 0;
}