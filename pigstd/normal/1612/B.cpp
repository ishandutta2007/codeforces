#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=110;
int n,a,b,p[M],vis[M];

signed main()
{
	WT
	{
		n=read(),a=read(),b=read();int l=1,r=n;
//		if (b+1<n/2||a-1>n/2||a==b){puts("-1");continue;}
		for (int i=1;i<=n;i++)vis[i]=0;
		for (int i=n;i>b;i--)p[l++]=i,vis[i]=1;
		for (int i=1;i<a;i++)p[r--]=i,vis[i]=1;
		while(l<=r)
		{
			for (int i=1;i<=n;i++)
				if (!vis[i]){p[l++]=i,vis[i]=1;break;}
		}int f=1;
		for (int i=1;i<=n;i++)if (!vis[i])f=0;
		int minn=n,maxn=0;
		for (int i=1;i<=n/2;i++)minn=min(minn,p[i]);
		for (int i=n/2+1;i<=n;i++)maxn=max(maxn,p[i]);
		if (minn!=a||maxn!=b)f=0;
		if (!f)puts("-1");
		else{for (int i=1;i<=n;i++)cout<<p[i]<<' ';puts("");}
	}
	return 0;
}