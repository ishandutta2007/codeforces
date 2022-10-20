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
ll sqr(ll x){return x*x;}
int p[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		ll ans=0;
		int n=read();
		if (n==2){puts("1\n2 1\n1\n2 1");continue;}
		if (n==3){puts("5\n2 3 1\n2\n1 3\n3 2");continue;}
		p[1]=n/2+1;
		p[n]=2;
		p[n/2]=1;
		for (int i=2;i<n/2;i++) p[i]=i+1;
		for (int i=n/2+1;i<n;i++) p[i]=i+1;
		vector<int>ans1;
		vector<pair<int,int>>ans2;
		for (int i=1;i<=n;i++) ans1.push_back(p[i]);
		for (int i=2;i<=n/2;i++)
		{
			ans+=sqr(n-p[n]);
			ans2.push_back(make_pair(p[n],n));
			swap(p[n],p[p[n]]);
		}
		for (int i=n/2+1;i<=n;i++)
		{
			ans+=sqr(p[1]-1);
			ans2.push_back(make_pair(p[1],1));
			swap(p[1],p[p[1]]);
		}
		print(ans);
		for (int i:ans1) print(i,' ');puts("");
		print(n-1);
		for (auto i:ans2) print(i.first,' '),print(i.second);
	}
	
	return 0;
}