#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;

ll get()
{
	char c=getchar();
	while (c<'a'||'z'<c) c=getchar();
	return c-'a';
}
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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
ll a[N];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	ll n=read(),m=read();
	for (ll i=1;i<=n;i++) a[i]=1LL<<get();
	m=m-a[n]+a[n-1];
	n-=2;
	sort(a+1,a+1+n,greater<ll>());
	for (ll i=1;i<=n;i++)
	if (abs(m-a[i])<abs(m+a[i])) m-=a[i];
							else m+=a[i];
	puts(m?"No":"Yes");
	
	return 0;
}