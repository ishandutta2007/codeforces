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
	int x,y;
}ans[N];
vector<node>d[N*2],e[N*2];

signed main()
{
	int n=read(),w=read(),h=read();
	for (int i=1;i<=n;i++)
	{
		int g=read(),u=read(),v=read();
		d[u-v+N].push_back((node){i,g==1?u:-v});
		e[u-v+N].push_back(g==1?(node){u,h}:(node){w,u});
	}
	for (int i=0;i<N*2;i++)
	{
		sort(d[i].begin(),d[i].end(),[&](const node &a,const node &b){
			return a.y<b.y;
		});
		sort(e[i].begin(),e[i].end(),[&](const node &a,const node &b){
			return a.x==b.x?a.y>b.y:a.x<b.x;
		});
		for (int k=0;k<(int)d[i].size();k++) ans[d[i][k].x]=e[i][k];
	}
	for (int i=1;i<=n;i++) print(ans[i].x,' '),print(ans[i].y);
	
	return 0;
}