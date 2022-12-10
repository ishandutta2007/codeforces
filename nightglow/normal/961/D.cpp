#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 300005
#define M 8000005

#define ls tree[t].l
#define rs tree[t].r
#define mid ((l+r)>>1)
#define Ls tree[t1].l
#define Rs tree[t1].r

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,vis[N];

struct Point{
	int x,y;
}A[N];

inline Point operator -(Point a,Point b)
{
		return (Point){a.x-b.x,a.y-b.y};
}

inline long long operator *(Point a,Point b)
{
		return 1ll*a.x*b.y-1ll*a.y*b.x;
}

int check(Point a,Point b)
{
		Point c=a-b;
		memset(vis,0,sizeof(vis));
		for (i=1;i<=n;++i)
			if (c*(a-A[i])==0) vis[i]=1;
		for (i=1;i<=n;++i)
			if (!vis[i]) break;
		for (j=i+1;j<=n;++j)
			if (!vis[j]) break;
		if (j>n) return 1;
		c=A[i]-A[j];
		for (j=1;j<=n;++j)
			if (!vis[j]&&c*(A[i]-A[j])!=0) return 0;
		return 1;
}

int main()
{
		scanf("%d",&n);
		if (n<=2) puts("YES");
		else
		{
				for (i=1;i<=n;++i) scanf("%d%d",&A[i].x,&A[i].y);
				if (check(A[1],A[2])||check(A[2],A[3])||check(A[1],A[3])) puts("YES");
				else puts("NO");
		}
}