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

const int inf=1e18;
const int M=5e5+10;
int n,m,a[M],b[M],p[M],f[M],ans;
int li[M],cnt;
map<int,int>t;

void solve(int l,int r)
{
	cnt=0;
	for (int i=l+1;i<r;i++)
	{
		if (a[i]<a[l]||a[i]>a[r])continue;
		int tl=1,tr=cnt,p=cnt+1;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (a[li[Mid]]>a[i])p=Mid,tr=Mid-1;
			else tl=Mid+1;
		}
		if (p==cnt+1)cnt++;
		li[p]=i;
	}
	ans+=r-l-1-cnt;
}

signed main()
{
	n=read(),m=read();a[0]=-inf,a[n+1]=inf;b[m+1]=n+1;
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=m;i++)b[i]=read();
	sort(b+1,b+1+m);
	for (int i=2;i<=m;i++)
		if (a[b[i]]-a[b[i-1]]<b[i]-b[i-1])return puts("-1"),0;
	for (int i=1;i<=n;i++)a[i]-=i,p[i]=a[i];
	sort(p+1,p+1+n);int cnt=0;
	for (int i=1;i<=n;i++)
		if (p[i]!=p[i-1]||i==1)t[p[i]]=++cnt;
	for (int i=1;i<=n;i++)
		a[i]=t[a[i]];
	for (int i=1;i<=m+1;i++)
		solve(b[i-1],b[i]);
	cout<<ans<<endl;
	return 0;
}
/*
7 2
1 2 1 1 3 5 1
3 5
*/