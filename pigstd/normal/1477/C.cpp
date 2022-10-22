#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=5010;
int n,p[M],vis[M];
struct node
{
	int x,y;
}a[M];

int dis(node a,node b)
{
	return (a.x-b.x)*(a.x-b.x)+(b.y-a.y)*(b.y-a.y);
}

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
		a[i].x=read(),a[i].y=read();
	p[1]=1;vis[1]=1;
	for (int i=1;i<=n-2;i++)
	{
		node maxn=a[p[i]];int f=-1;
		for (int j=1;j<=n;j++)
			if (!vis[j]&&dis(maxn,a[p[i]])<dis(a[p[i]],a[j]))
				f=j,maxn=a[j];
		p[i+1]=f;vis[f]=1;
	}
	for (int i=1;i<=n;i++)
		if (!vis[i])p[n]=i;
	for (int i=1;i<=n;i++)cout<<p[i]<<' ';
	return 0;
}