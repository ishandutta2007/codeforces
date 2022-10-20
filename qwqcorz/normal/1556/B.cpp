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
int a[N],b[N];
ll Multi_test_no_horses()
{
	int n=read(),cnt[2]={};
	for (int i=1;i<=n;i++) cnt[a[i]=read()&1]++;
	if (abs(cnt[0]-cnt[1])>1) return -1;
	ll ans=1e18;
	if (n&1)
	{
		if (cnt[1]>cnt[0]) for (int i=1,j=1;i<=cnt[1];i++,j+=2) b[i]=j;
					  else for (int i=1,j=2;i<=cnt[1];i++,j+=2) b[i]=j;
		ll now=0;
		for (int i=1,j=1;i<=n;i++) if (a[i]) now+=abs(i-b[j++]);
		ans=now;
	}
	else
	{
		ll now=0;
		for (int i=1,j=1;i<=n;i++) if (a[i]) now+=abs(i-j),j+=2;
		ans=now,now=0;
		for (int i=1,j=2;i<=n;i++) if (a[i]) now+=abs(i-j),j+=2;
		ans=min(ans,now);
	}
	return ans;
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
//	int T=1;
	int T=read();
	while (T--) print(Multi_test_no_horses());
	
	return 0;
}