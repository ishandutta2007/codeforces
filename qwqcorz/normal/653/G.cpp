#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
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
	if (x<0) putchar('-');
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
int fact[N],inv[N],sum[N];
int mn[N],a[N],ans=0;
vector<int>b[N];
void ysgs(int n)
{
	for (int i=2;i<=n;i++) if (!mn[i])
	for (int j=i;j<=n;j+=i) if (!mn[j]) mn[j]=i;
	for (int i=fact[0]=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
	inv[n]=power(fact[n],p-2);
	for (int i=n;i>=1;i--) inv[i-1]=1LL*inv[i]*i%p;
}
int C(int n,int m)
{
	if (n<m||m<0) return 0;
	return 1LL*fact[n]*inv[m]%p*inv[n-m]%p;
}
int calc(int l,int r)
{
	if (l>r) return 0;
	if (l==0) return sum[r];
	return (sum[r]-sum[l-1]+p)%p;
}

signed main()
{
	ysgs(1e6);
	int n=read();
	for (int i=1;i<=n;i++)
	{
		int x=a[i]=read();
		while (x>1)
		{
			int now=mn[x],cnt=0;
			while (x%now==0) x/=now,cnt++;
			b[now].push_back(cnt);
		}
	}
	for (int i=0;i<=n-1;i++) sum[i]=C(n-1,i);
	for (int i=1;i<=n-1;i++) sum[i]=(sum[i]+sum[i-1])%p;
	for (int i=2;i<=1e6;i++)
	if (!b[i].empty())
	{
		sort(b[i].begin(),b[i].end());
		auto &now=b[i];
		int tot=n-now.size();
		for (int i=0;i<(int)now.size();i++)
		{
			int id=tot+i+1;
			ans=(ans+1LL*now[i]*(calc(0,id-2)-calc(id,n-1)+p))%p;
		}
	}
	print(ans);
	
	return 0;
}