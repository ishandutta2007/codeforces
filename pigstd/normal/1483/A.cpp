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

const int M=2e5+10;
int n,m,cnt[M],ans[M],t[M];
vector<int>v[M];

signed main()
{
	WT
	{
		n=read(),m=read();int sum=0;
		for (int i=1;i<=m;i++)v[i].clear();
		for (int i=1;i<=n;i++)cnt[i]=0;
		for (int i=1;i<=m;i++)
		{
			int x=read();t[i]=x;
			for (int j=1;j<=x;j++)v[i].pb(read());
			if (x==1)cnt[v[i][0]]++,ans[i]=v[i][0];
		}
		for (int i=1;i<=n;i++)sum=max(sum,cnt[i]);
		if (sum>(m+1)/2){NO continue;}YES
		for (int i=1;i<=m;i++)
		{
			if (t[i]==1)continue;
			int x=v[i][1],y=v[i][0];
			if (cnt[x]>cnt[y])cnt[y]++,ans[i]=y;
			else cnt[x]++,ans[i]=x;
		}
		for (int i=1;i<=m;i++)
			cout<<ans[i]<<' ';puts("");
	}
	return 0;
}