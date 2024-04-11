#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1111;
const ll inf=1ll<<60;

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
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
ll a[N];
vector<ll>MaxL[N],MaxR[N],Min;

signed main()
{
	ll n=read(),m=read(),ans=-inf;
	for (ll i=1;i<=n;i++) a[i]=read();
	for (ll i=1;i<=n;i++)
	{
		MaxL[i]=MaxL[i-1];
		ll now=MaxL[i].size();
		if (now<m) MaxL[i].push_back(0);
		while (now&&MaxL[i][now-1]<a[i])
		{
			if (now<m) MaxL[i][now]=MaxL[i][now-1];
			now--;
		}
		if (now<m) MaxL[i][now]=a[i];
	}
	for (ll i=n;i>=1;i--)
	{
		MaxR[i]=MaxR[i+1];
		ll now=MaxR[i].size();
		if (now<m) MaxR[i].push_back(0);
		while (now&&MaxR[i][now-1]<a[i])
		{
			if (now<m) MaxR[i][now]=MaxR[i][now-1];
			now--;
		}
		if (now<m) MaxR[i][now]=a[i];
	}
	for (ll i=1;i<=n;i++)
	{
		Min.clear();
		for (ll j=i,sum=a[i];j<=n;sum+=a[++j])
		{
			ll now=Min.size();
			if (now<m) Min.push_back(0);
			while (now&&Min[now-1]>a[j])
			{
				if (now<m) Min[now]=Min[now-1];
				now--;
			}
			if (now<m) Min[now]=a[j];
//					print(i,' ');
//					print(j,':');
//					for (int k=0;k<Min.size();k++)
//					print(Min[k],' ');
//					puts("");
			ll tmp=sum;
			ans=max(ans,sum);
			for (ll k=0,x=0,y=0;k<Min.size();k++)
			{
				if (x==MaxL[i-1].size()&&y==MaxR[j+1].size()) break;
				if (y==MaxR[j+1].size()||(x<MaxL[i-1].size()&&MaxL[i-1][x]>MaxR[j+1][y]))
				{
					if (Min[k]>=MaxL[i-1][x]) break;
					tmp+=MaxL[i-1][x]-Min[k];
					x++;
				}
				else
				{
					if (Min[k]>=MaxR[j+1][y]) break;
					tmp+=MaxR[j+1][y]-Min[k];
					y++;
				}
				ans=max(ans,tmp);
			}
		}
	}
	print(ans);

	return 0;
}