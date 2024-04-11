#include<bits/stdc++.h>
#define mk make_pair
using namespace std;
const int N=2e3+5;

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
vector<pair<int,int>>ans;
int p[N],q[N],cost;
void Swap(int x,int y)
{
	ans.push_back(mk(x,y));
	swap(q[p[x]],q[p[y]]);
	swap(p[x],p[y]);
	cost+=y-x;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read();
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<=n;i++) q[read()]=i;
	for (int i=1;i<=n;i++) p[i]=q[p[i]];
	for (int i=1;i<=n;i++) q[p[i]]=i;
	for (int i=n;i>=1;i--)
	{
		int now=q[i];
		for (int j=now+1;j<=i;j++) if (p[j]<=now) Swap(now,j),now=j;
	}
	print(cost);
	print(ans.size());
	for (auto i:ans) print(i.first,' '),print(i.second);
	
	return 0;
}