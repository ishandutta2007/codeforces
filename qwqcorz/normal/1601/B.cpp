#include<bits/stdc++.h>
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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
pair<int,int>mn[N];
int a[N],b[N];
bool vis[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(); mn[n+1]=make_pair(N,N);
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=i+read();
	for (int i=1;i<=n;i++) b[i]=b[i]-a[b[i]];
	for (int i=n;i>=1;i--) mn[i]=min(mn[i+1],make_pair(b[i],i));
	vector<int>ans;
	int now=n-a[n];
	while (now)
	{
		now=mn[now].second;
		if (vis[now]) return puts("-1"),0;
		ans.push_back(now);
		vis[now]=1;
		now=b[now];
	}
	if (ans.empty()||ans.back()!=0) ans.push_back(0);
	print(ans.size());
	for (int i:ans) print(i,' ');
	
	return 0;
}