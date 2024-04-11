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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
char a[N];
int len[N],cnt=1,tot[N];
bool vis[N];
void solve(int t)
{
	vector<int>ans;
	for (int i=1;i<=cnt;i++)
	{
		len[i]-=t;
		while (len[i])
		if (len[i]==3) ans.push_back(2),len[i]-=3;
				  else ans.push_back(1),len[i]-=2;
		if (i<cnt) ans.push_back(t+tot[i]);
	}
	print(ans.size());
	for (int i:ans) print(i,' ');
	exit(0);
}
bool check0()
{
	for (int i=1;i<=cnt;i++)
	if (len[i]) return 0;
	return 1;
}
bool check1()
{
	for (int i=1;i<=cnt;i++)
	if (len[i]%2==0) return 0;
	return 1;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	scanf("%s",a+1);
	int n=strlen(a+1);
	for (int i=1;i<=n;i++)
	if (a[i]=='_') len[cnt]++;
	else
	{
		if (a[i]=='#'&&a[i-1]!=a[i]) cnt++;
		if (a[i]=='#') tot[cnt-1]++;
	}
	for (int i=2;i<cnt;i++) len[i]--;
	int up=n;
	for (int i=1;i<=cnt;i++) up=min(up,len[i]),vis[len[i]-1]=1;
	for (int i=2;i<=up;i++) if (!vis[i]) solve(i);
	if (check1()) solve(1);
	if (check0()) solve(0);
	puts("-1");
	
	return 0;
}