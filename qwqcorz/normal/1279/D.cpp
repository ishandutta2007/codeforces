#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int p=998244353;

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
vector<int>a[N];
int tot[N],k[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),ans=0;
	for (int i=1;i<=n;i++)
	{
		k[i]=read();
		for (int j=1;j<=k[i];j++)
		{
			int x=read();
			a[i].push_back(x);
			tot[x]++;
		}
	}
	for (int i=1,inv=power(n,p-2);i<=n;i++)
	for (int j:a[i])
	ans=(ans+1LL*inv*power(k[i],p-2)%p*tot[j]%p*inv)%p;
	print(ans);
	
	return 0;
}