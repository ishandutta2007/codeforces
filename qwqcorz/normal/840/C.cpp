#include<bits/stdc++.h>
using namespace std;
const int N=305;
const int p=1e9+7;

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
int power(int a,int b)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=1LL*ret*a%p;
		a=1LL*a*a%p;
		b/=2;
	}
	return ret;
}
int a[N],t[N],fact[N],inv[N];
vector<int>G,F;
void ysgs(int n)
{
	for (int i=fact[0]=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
	inv[n]=power(fact[n],p-2);
	for (int i=n;i>=1;i--) inv[i-1]=1LL*inv[i]*i%p;
}
vector<int>MTT(vector<int>F,vector<int>G)
{
	int n=F.size(),m=G.size();
	vector<int>H(n+m-1);
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	H[i+j]=(H[i+j]+1LL*F[i]*G[j])%p;
	return H;
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),m=0;
	ysgs(n);
	for (int i=1;i<=n;i++)
	{
		a[i]=1;
		int x=read();
		for (int j=2;j*j<=x;j++)
		if (x%j==0)
		{
			int flag=0;
			while (x%j==0) x/=j,flag^=1;
			if (flag) a[i]*=j;
		}
		if (x>1) a[i]*=x;
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
	if (a[i]!=a[i-1]) t[++m]=1;
				 else t[m]++;
	F.push_back(1);
	for (int i=1;i<=m;i++)
	{
		int mul=1;
		for (int j=t[i];j>=1;j--)
		{
			G.push_back(1LL*mul*inv[t[i]-j]%p);
			mul=1LL*mul*j*(j-1)%p;
		}
		F=MTT(F,G);
		G.clear();
	}
	int ans=0;
	for (int i=0;i<(int)F.size();i++) ans=(ans+(i%2?-1LL:1LL)*F[i]*fact[n-i]%p+p)%p;
	print(ans);
	
	return 0;
}