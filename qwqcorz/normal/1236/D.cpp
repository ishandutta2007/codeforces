#include<bits/stdc++.h>
#define ll long long
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
int n,m,k;
vector<int>h[N],l[N];
bool check(int tmp)
{
	int x=1,y=1,f=tmp,x1=0,y1=0,x2=n+1,y2=m+1;
	ll tot=1;
	while (1)
	{
		if (f==0)
		{
			int pos=lower_bound(h[x].begin(),h[x].end(),y)-h[x].begin();
			int ny=min(y2,h[x][pos])-1;
			tot+=ny-y;
			if (ny==y) break;
			x1=x;
			y=ny;
		}
		if (f==2)
		{
			int pos=lower_bound(h[x].begin(),h[x].end(),y)-h[x].begin()-1;
			int ny=max(y1,h[x][pos])+1;
			tot+=y-ny;
			if (ny==y) break;
			x2=x;
			y=ny;
		}
		if (f==1)
		{
			int pos=lower_bound(l[y].begin(),l[y].end(),x)-l[y].begin();
			int nx=min(x2,l[y][pos])-1;
			tot+=nx-x;
			if (nx==x) break;
			y2=y;
			x=nx;
		}
		if (f==3)
		{
			int pos=lower_bound(l[y].begin(),l[y].end(),x)-l[y].begin()-1;
			int nx=max(x1,l[y][pos])+1;
			tot+=x-nx;
			if (nx==x) break;
			y1=y;
			x=nx;
		}
		f++;
		if (f>=4) f=0;
	}
	return tot+k==1LL*n*m;
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	n=read(),m=read(),k=read();
	for (int i=1;i<=k;i++)
	{
		int x=read(),y=read();
		h[x].push_back(y);
		l[y].push_back(x);
	}
	for (int i=1;i<=n;i++) h[i].push_back(0),h[i].push_back(m+1);
	for (int i=1;i<=m;i++) l[i].push_back(0),l[i].push_back(n+1);
	for (int i=1;i<=n;i++) sort(h[i].begin(),h[i].end());
	for (int i=1;i<=m;i++) sort(l[i].begin(),l[i].end());
	puts(check(0)||check(1)?"Yes":"No");
	
	return 0;
}