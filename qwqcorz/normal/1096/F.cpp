#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
const int p=998244353ll;

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
int power(int a,int b)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=ret*a%p;
		a=a*a%p;
		b/=2;
	}
	return ret;
}
int t[N],fact[N],a[N],b[N],n,k=0,cnt=0,tot=0,ans=0;
void add(int x)
{
	for (;x<=n;x+=x&-x) t[x]++;
}
int query(int x)
{
	int ret=0;
	for (;x;x-=x&-x) ret+=t[x];
	return ret;
}

signed main()
{
	memset(t,0,sizeof(t));
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		if (a[i]>=0) b[a[i]]=1;
	}
	for (int i=n;i>=1;i--) b[i]+=b[i+1];
	for (int i=n;i>=1;i--) b[i]=n-i+1-b[i];
	fact[0]=1;
	for (int i=1;i<=n;i++) fact[i]=fact[i-1]*i%p;
	for (int i=1;i<=n;i++) k+=a[i]<0;
	for (int i=1;i<=n;i++)
	if (a[i]>0)
	{
		ans=(ans+(query(n)-query(a[i]))*fact[k]%p)%p;
		add(a[i]);
		cnt+=k-b[a[i]];
		ans=(ans+b[a[i]]*tot%p*fact[max(k-1,0ll)]%p)%p;
	}
	else
	{
		ans=(ans+cnt*fact[k-1]%p)%p;
		ans=(ans+k*(k-1)/2ll%p*tot%p*fact[max(k-2,0ll)]%p)%p;
		tot++;
	}
//	print(ans);
	print(ans*power(fact[k],p-2)%p);

	return 0;
}