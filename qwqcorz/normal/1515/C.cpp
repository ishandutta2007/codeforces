#include<bits/stdc++.h>
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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct node
{
	int pos,tot;
	bool operator <(const node &a)const
	{
		return tot>a.tot;
	}
};
priority_queue<node>q;
int a[N];

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read(),m=read(),x=read();
		(void)x;
		for (int i=1;i<=n;i++) a[i]=read();
		while (!q.empty()) q.pop();
		for (int i=1;i<=m;i++) q.push((node){i,0});
		puts("YES");
		for (int i=1;i<=n;i++)
		{
			node qwq=q.top();
			q.pop();
			print(qwq.pos,' ');
			qwq.tot+=a[i];
			q.push(qwq);
		}
		puts("");
	}

	return 0;
}