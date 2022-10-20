#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;
const ll Add=998244353ll;
const ll Mod=1919810111ll;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
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
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
ll n,fail[N],Z[N];
char a[N],b[N];
struct hash
{
	ll h[N],Pow[N],n;
	char a[N];
	void send(char *A)
	{
		n=strlen(A+1);
		for (ll i=1;i<=n;i++) a[i]=A[i];
		for (ll i=1;i<=n;i++) h[i]=(h[i-1]*127ll+a[i]+Add)%Mod;
		for (ll i=Pow[0]=1;i<=n;i++) Pow[i]=Pow[i-1]*127ll%Mod;
	}
	ll get(ll l,ll r)
	{
		return (h[r]-h[l-1]*Pow[r-l+1]%Mod+Mod)%Mod;
	}
}h1;
struct hash_rev
{
	ll h[N],Pow[N],n;
	char a[N];
	void send(char *A)
	{
		n=strlen(A+1);
		for (ll i=1;i<=n;i++) a[i]=A[i];
		for (ll i=n;i>=1;i--) h[i]=(h[i+1]*127ll+a[i]+Add)%Mod;
		for (ll i=Pow[0]=1;i<=n;i++) Pow[i]=Pow[i-1]*127ll%Mod;
	}
	ll get(ll l,ll r)
	{
		return (h[l]-h[r+1]*Pow[r-l+1]%Mod+Mod)%Mod;
	}
}h2;
ll AnsX=-1,AnsY=-1;

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	scanf("%[^\n]",a+1);
	scanf("%*[\n]%[^\n]",b+1);
	if ((n=strlen(a+1))!=strlen(b+1)||n<2) return puts("-1 -1"),0;
	reverse(a+1,a+1+n);
	for (ll i=2,j=0;i<=n;i++)
	{
		while (j&&a[j+1]!=a[i]) j=fail[j];
		if (a[j+1]==a[i]) j++;
		fail[i]=j;
	}
	h1.send(a);
	h2.send(b);
	for (ll i=1,j=0;i<=n;i++)
	{
		while (j&&a[j+1]!=b[i]) j=fail[j];
		if (a[j+1]==b[i]) j++;
		if (j==i&&i>1) j=fail[j];
		Z[i]=j;
	}
	for (ll i=n;i>=1;i--)
	{
		if (i<n&&Z[i]&&h1.get(Z[i]+1,i)==h2.get(1,i-Z[i]))
		{
			AnsX=n-(i+1);
			AnsY=n-Z[i];
		}
		if (a[i]!=b[i]) break;
	}
	print(AnsX,' ');
	print(AnsY);

	return 0;
}