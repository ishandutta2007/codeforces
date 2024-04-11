#include<bits/stdc++.h>
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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int siz[N];
vector<int>e[N];
void shootme()
{
	priority_queue<int,vector<int>,greater<int>>q,q0;
	int n=read();
	for (int i=1;i<=n;i++) e[i].clear();
	for (int i=1;i<=n;i++)
	{
		siz[i]=read();
		for (int j=1;j<=siz[i];j++) e[read()].push_back(i);
	}
	int tot=0,ans=0;
	for (int i=1;i<=n;i++) if (!siz[i]) q.push(i);
	while (!q.empty())
	{
		ans++;
		while (!q.empty())
		{
			tot++;
			int now=q.top(); q.pop();
			for (int to:e[now])
			if (!--siz[to])
			{
				if (to>now) q.push(to);
					   else q0.push(to);
			}
		}
		swap(q,q0);
	}
	if (tot<n) puts("-1");
		  else print(ans);
}

signed main()
{
	int T=read();
	while (T--) shootme();
	
	return 0;
}