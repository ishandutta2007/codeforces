#include<bits/stdc++.h>
#define int long long
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
	int pos,time;
	bool operator <(const node &a)const
	{
		return time==a.time?pos<a.pos:time<a.time;
	}
}a[N];
queue<int>q1;
priority_queue<int,vector<int>,greater<int> >q2;
int ans[N];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),k=read();
	for (int i=1;i<=n;i++) a[i]=(node){i,read()};
	sort(a+1,a+1+n);
	for (int i=1,j=1,now=0;i<=n;i++)
	{
		if (q1.empty()&&q2.empty()&&j<=n) now=a[j].time;
		now+=k;
		while (j<=n&&a[j].time<=now)
		if (q1.empty()||a[j].pos<q1.back()) q1.push(a[j++].pos);
									   else q2.push(a[j++].pos);
		ans[q1.front()]=now;
		q1.pop();
		if (!q2.empty()&&q1.empty())
		q1.push(q2.top()),q2.pop();
	}
	for (int i=1;i<=n;i++) print(ans[i],' ');
	
	return 0;
}