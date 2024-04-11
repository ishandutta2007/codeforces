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
struct bit
{
	int n,t[N];
	void send(int _n){n=_n,memset(t,0x3f,sizeof(int)*(n+1));}
	void add(int x,int y){for (;x;x&=x-1) t[x]=min(t[x],y);}
	int query(int x){int ret=t[0];for (;x<=n;x+=x&-x) ret=min(ret,t[x]);return ret;}
}t;
queue<int>q[N];
int a[N],b[N],p[N];
bool GreenDay()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=1;i<=n;i++) while (!q[i].empty()) q[i].pop();
	for (int i=1;i<=n;i++) q[b[i]].push(i);
	for (int i=1;i<=n;i++)
	if (q[a[i]].empty()) return 0;
	else p[i]=q[a[i]].front(),q[a[i]].pop();
	t.send(n);
	for (int i=1;i<=n;i++)
	{
		if (t.query(p[i])<a[i]) return 0;
		t.add(p[i],a[i]);
	}
	return 1;
}

signed main()
{
	int T=read();
	while (T--) puts(GreenDay()?"YES":"NO");
	
	return 0;
}