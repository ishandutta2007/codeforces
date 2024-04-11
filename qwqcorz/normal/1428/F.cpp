#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;

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
char a[N];
ll last[N];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	ll n=read(),sum=0,ans=0,now=0;
	scanf("%s",a+1);
	for (ll i=1;i<=n;i++)
	{
		if (a[i]=='1') now++,sum+=i-last[now];
		else while (now) last[now]=i-now,now--;
		ans+=sum;
	}
	print(ans);
	
	return 0;
}