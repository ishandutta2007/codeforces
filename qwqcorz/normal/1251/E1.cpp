#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;

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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct node
{
	int p,m;
	bool operator <(const node &a)const
	{
		return m>a.m;
	}
}a[N];
priority_queue<int,vector<int>,greater<int> >q;

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int T=read();
	while (T--)
	{
		int n=read(),ans=0;
		for (int i=1;i<=n;i++)
			a[i].m=read(),
			a[i].p=read();
		sort(a+1,a+1+n);
		a[n+1].m=-1;
		while (!q.empty()) q.pop();
		for (int i=1,tot=0;i<=n;i++)
		{
			q.push(a[i].p);
			if (a[i].m!=a[i+1].m)
			{
				int tmp=a[i].m-(n-i)-tot;
				while (tmp>0)
				{
					ans+=q.top();
					q.pop();
					tmp--;
					tot++;
				}
			}
		}
		print(ans);
	}
	
	return 0;
}