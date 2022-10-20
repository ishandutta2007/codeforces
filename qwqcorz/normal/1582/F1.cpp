#include<bits/stdc++.h>
using namespace std;
const int m=512;

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
bool vis[m][m];
int x[m][m],p[m];
vector<int>a[m];
struct node
{
	int x,y,z;
	bool operator <(const node &a)const
	{
		return z>a.z;
	}
};
priority_queue<node>q;

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	memset(x,0x3f,sizeof(x));
	int n=read(); 
	for (int i=1;i<=n;i++) a[read()].push_back(i);
	for (int i=0;i<m;i++) if (!a[i].empty()) q.push((node){i,i,x[i][i]=a[i][0]});
	while (!q.empty())
	{
		int nx=q.top().x,ny=q.top().y; q.pop();
		if (vis[nx][ny]) break;
		vis[nx][ny]=1;
		for (int i=nx+1;i<m;i++)
		if (!vis[i][ny^i])
		{
			while (p[i]<(int)a[i].size()&&a[i][p[i]]<=x[nx][ny]) p[i]++;
			if (p[i]<(int)a[i].size()&&a[i][p[i]]<x[i][ny^i])
			q.push((node){i,ny^i,x[i][ny^i]=a[i][p[i]]});
		}
	}
	vis[0][0]=1;
	vector<int>ans;
	for (int i=0;i<m;i++)
	{
		bool flag=0;
		for (int j=0;j<m;j++) flag|=vis[j][i];
		if (flag) ans.push_back(i);
	}
	print(ans.size());
	for (int i:ans) print(i,' ');
	
	return 0;
}