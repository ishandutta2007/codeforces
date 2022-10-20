#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
ll ans=0;
bool vis[N];
vector<int>fac[N];
int a[N],mu[N],cnt[N];
int calc(int x)
{
	int ret=0;
	for (int i:fac[x]) ret+=mu[i]*cnt[i];
	return ret;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),m=0;
	for (int i=1;i<=n;i++) m=max(m,a[i]=read());
	for (int i=1;i<=m;i++)
	for (int j=i;j<=m;j+=i)
	fac[j].push_back(i);
	for (int i=mu[1]=1;i<=m;i++)
	for (int j=i*2;j<=m;j+=i)
	mu[j]-=mu[i];
	for (int i=1;i<=n;i++) vis[a[i]]=1;
	for (int i=1;i<=m;i++) if (vis[a[i]])
	for (int j:fac[a[i]]) vis[j]=1;
	n=0;
	for (int i=1;i<=m;i++) if (vis[i]) a[++n]=i;
	for (int i=1;i<=n;i++)
	for (int j:fac[a[i]]) cnt[j]++;
	for (int i=n,j=1;j<=i;i--)
	while (j<=i&&calc(a[i]))
	{
		if (gcd(a[j],a[i])==1) ans=max(ans,1LL*a[i]*a[j]);
		for (int k:fac[a[j]]) cnt[k]--;
		j++;
	}
	print(ans);
	
	return 0;
}