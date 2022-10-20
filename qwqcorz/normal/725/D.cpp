#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+5;

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
struct node
{
	int t,w;
	bool operator <(const node &a)const
	{
		return t>a.t;
	}
}a[N];
priority_queue<int,vector<int>,greater<int> >q;

signed main()
{
	int n=read()-1,ans=n+114514,now=1;
	for (int i=0;i<=n;i++)
	{
		a[i].t=read();
		a[i].w=read();
	}
	sort(a+1,a+1+n);
	int T=a[0].t;
	while (1)
	{
		while (now<=n&&a[now].t>T)
		{
			q.push(a[now].w-a[now].t+1);
			now++;
		}
		ans=min(ans,(int)q.size()+1);
		if (!q.empty()&&q.top()<=T)
		{
			T-=q.top();
			q.pop();
		}
		else break;
	}
	print(ans);

	return 0;
}