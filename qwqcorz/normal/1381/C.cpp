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
vector<int>b[N];
int a[N],ans[N],pos;
int solve(int n)
{
	vector<int>p;
	for (int i=1;i<=n+1;i++) if (!b[i].empty()) p.push_back(i);
	if ((int)p.size()<=1) return 0;
	ans[b[p[0]].back()]=a[b[p[1]].back()];
	pos=b[p[1]].back();
	return 1;
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int T=read();
	while (T--)
	{
		pos=0;
		int n=read(),x=read(),y=read()-x,v=0;
		for (int i=1;i<=n;i++) ans[i]=0;
		for (int i=1;i<=n+1;i++) b[i].clear();
		for (int i=1;i<=n;i++) b[a[i]=read()].push_back(i);
		vector<int>p;
		int mx=0;
		for (int i=1;i<=n+1;i++)
		if (b[i].empty()) v=i;
		else
		{
			int tot=min({(int)b[i].size(),y/2,y-(int)p.size()});
			mx=max(mx,tot);
			while (tot --> 0) p.push_back(b[i].back()),b[i].pop_back();
		}
		if ((int)p.size()<y-1){puts("NO");continue;}
		for (int i=0;i<(int)p.size();i++) ans[p[(i+mx)%(int)p.size()]]=a[p[i]];
		if ((int)p.size()==y-1) if (!solve(n)){puts("NO");continue;}
		for (int i=1;i<=n&&x;i++) if (!ans[i]&&i!=pos) ans[i]=a[i],x--;
		for (int i=1;i<=n;i++) if (!ans[i]) ans[i]=v;
		if (x){puts("NO");continue;}
		puts("YES");
		for (int i=1;i<=n;i++) print(ans[i]," \n"[i==n]);
	}
	
	return 0;
}