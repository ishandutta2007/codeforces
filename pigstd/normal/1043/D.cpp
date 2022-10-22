#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
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

const int M=1e5+10;
const int N=12;
int a[N][M],t[M],t1[N][M],t2[N][M],n,m,ans;

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			a[i][j]=read();
	for (int i=1;i<=n;i++)
		t[a[1][i]]=i;
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
			a[i][j]=t[a[i][j]],t1[i][a[i][j]]=j;
	}
	for (int i=1;i<=m;i++)
		for (int j=2;j<=n;j++)
			if (t1[i][j]==t1[i][j-1]+1)
				t2[i][j]=t2[i][j-1]+1;
	for (int i=1;i<=n;i++)
	{
		int minn=i-1;
		for (int j=2;j<=m;j++)
			minn=min(minn,t2[j][i]);
		ans+=minn+1;
	}cout<<ans<<endl;
	return 0;
}