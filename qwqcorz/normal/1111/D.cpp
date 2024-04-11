#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int p=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

#define add(x,y) ((x+=y)>=p?x-=p:0)
int power(int a,int b)
{
	int ret=1;
	for (;b;a=1LL*a*a%p,b/=2) if (b&1) ret=1LL*ret*a%p;
	return ret;
}
int fact[N],invf[N];
void ysgs(int n)
{
	for (int i=fact[0]=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
	invf[n]=power(fact[n],p-2);
	for (int i=n;i>=1;i--) invf[i-1]=1LL*invf[i]*i%p;
}
int C(int n,int m)
{
	if (n<m||m<0) return 0;
	return 1LL*fact[n]*invf[m]%p*invf[n-m]%p;
}
int a[N],tot[55];
char s[N];
int ans[55][55],f[55][N/2],g[55][N/2];

signed main()
{
	ysgs(1e5);
	scanf("%s",s+1);
	int n=strlen(s+1);
	for (int i=1;i<=n;i++)
	if ('a'<=s[i]&&s[i]<='z') tot[a[i]=s[i]-'a'+1]++;
						 else tot[a[i]=s[i]-'A'+27]++;
	int all=1LL*fact[n/2]*fact[n/2]%p;
	for (int i=1;i<=52;i++) all=1LL*all*invf[tot[i]]%p;
	for (int k=1;k<=52;k++)
	if (tot[k])
	{
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		f[0][0]=1;
		for (int j=1,sum=0;j<=52;j++)
		if (j!=k)
		{
			sum+=tot[j];
			for (int i=0;i<=min(sum,n/2);i++)
			{
				add(f[j][i],f[j-1][i]);
				if (i>=tot[j]&&tot[j]) add(f[j][i],f[j-1][i-tot[j]]);
			}
		}
		else for (int i=0;i<=min(sum,n/2);i++) f[j][i]=f[j-1][i];
		g[53][0]=1;
		for (int j=52,sum=0;j>=1;j--)
		if (j!=k)
		{
			sum+=tot[j];
			for (int i=0;i<=min(sum,n/2);i++)
			{
				add(g[j][i],g[j+1][i]);
				if (i>=tot[j]&&tot[j]) add(g[j][i],g[j+1][i-tot[j]]);
			}
		}
		else for (int i=0;i<=min(sum,n/2);i++) g[j][i]=g[j+1][i];
		for (int j=k+1;j<=52;j++)
		for (int i=0;i<=n/2;i++)
		ans[k][j]=(ans[k][j]+1LL*f[j-1][i]*g[j+1][n/2-i])%p;
		ans[0][0]=f[52][n/2];
	}
	int Q=read();
	while (Q--)
	{
		int x=a[read()],y=a[read()];
		if (x>y) swap(x,y);
		if (x==y) print(2LL*ans[0][0]*all%p);
			 else print(2LL*ans[x][y]*all%p);
	}
	
	return 0;
}