#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e3+5;
const int inf=1ll<<60;

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
priority_queue<int,vector<int>,greater<int> >q;
vector<int>a[N];

signed main()
{
	int n=read(),m=read(),ans=inf;
	for (int i=1;i<=n;i++)
	{
		int p=read(),c=read();
		a[p].push_back(c);
	}
	for (int i=1;i<=m;i++) sort(a[i].begin(),a[i].end());
	for (int t=a[1].size();t<=n;t++)
	{
		while (!q.empty()) q.pop();
		int sum=0,now=a[1].size(),Max=0;
		for (int i=2;i<=m;i++)
		{
			int p=max(((int)a[i].size())-t,0ll);
			Max=max(Max,((int)a[i].size())-p);
			now+=p;
			for (int j=0;j<p;j++) sum+=a[i][j];
			for (int j=p;j<a[i].size();j++) q.push(a[i][j]);
		}
		while (now<=Max)
		{
			sum+=q.top();
			q.pop();
			now++;
		}
		ans=min(ans,sum);
	}
	print(ans);

	return 0;
}