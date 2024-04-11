#include<bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=3e3+5;

int get()
{
	char c=getchar();
	while (c!='.'&&c!='z') c=getchar();
	return c=='z';
}
int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct BIT
{
	int t[N],n;
	void add(int x,int y)
	{
		x++;
		for (;x<=n;x+=x&-x) t[x]+=y;
	}
	int query(int x)
	{
		x++;
		int ret=0;
		for (;x;x=x&(x-1)) ret+=t[x];
		return ret;
	}
}t;
ll ans;
int a[N][N],l[N][N],r[N][N];
priority_queue<pair<int,int>>q;
void clear()
{
	while (!q.empty())
	{
		t.add(q.top().se,-1);
		q.pop();
	}
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),m=read();t.n=m+1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) a[i][j]=get();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) l[i][j]=a[i][j]?l[i][j-1]+1:0;
	for (int i=1;i<=n;i++)
	for (int j=m;j>=1;j--) r[i][j]=a[i][j]?r[i][j+1]+1:0;
	for (int tx=1;tx<=n;tx++)
	for (int ty=1;ty<=m;ty++)
	if (tx==1||ty==m)
	{
		for (int x=tx,y=ty;x<=n&&y>=1;x++,y--)
		if (a[x][y])
		{
			while (!q.empty()&&q.top().fi>=y)
			{
				t.add(q.top().se,-1);
				q.pop();
			}
			t.add(y,1);
			q.push(mk(y-l[x][y],y));
			ans+=t.query(y+r[x][y]-1);
		}
		else clear();
		clear();
	}
	print(ans);
	
	return 0;
}