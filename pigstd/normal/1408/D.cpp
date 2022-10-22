#include<bits/stdc++.h>
using namespace std;

const int M=2005;
int a[M],b[M],c[M],d[M],maxn,n,m,ans=1e9;

struct node
{
	int x,y;
}p[M*M];int cnt;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

bool cmp(node a,node b)
{
	return a.x>b.x||(a.x==b.x&&a.y<b.y);
}

int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)a[i]=read(),b[i]=read();
	for (int i=1;i<=m;i++)c[i]=read(),d[i]=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i]<=c[j]&&b[i]<=d[j])
			{
				maxn=max(maxn,d[j]-b[i]+1);
				p[++cnt].x=c[j]-a[i]+1,p[cnt].y=d[j]-b[i]+1;
			}
	p[++cnt].x=0,p[cnt].y=maxn;maxn=0;
	sort(p+1,p+1+cnt,cmp);
	for (int i=1;i<=cnt;i++)ans=min(ans,maxn+p[i].x),maxn=max(maxn,p[i].y);
	cout<<ans;
	return 0;
}