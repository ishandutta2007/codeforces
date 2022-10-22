#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=110;
int n,a[M][M],cnt[M][M];
vector<vector<int>>ans;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)for (int j=1;j<=n;j++)cnt[i][a[i][j]=read()]++;
	while(1)
	{
		int F=-1;vector<int>v;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
				if (cnt[i][j]!=1)F=i;
		}
		if (F==-1)break;
		v.resize(n);int lst=-1;
		for (int i=F;i<=n;i++)
		{
			int pos=-1;
			for (int j=1;j<=n;j++)
				if (cnt[i][j]>1)pos=j;
			if (pos==-1)pos=lst;v[i-1]=lst=pos;
		}
		for (int i=1;i<F;i++)
		{
			int pos=-1;
			for (int j=1;j<=n;j++)
				if (cnt[i][j]>1)pos=j;
			if (pos==-1)pos=lst;v[i-1]=lst=pos;
		}
		ans.pb(v);
		for (int i=1;i<=n;i++)cnt[i][v[i-1]]--,cnt[i][v[(i-2+n)%n]]++;
	}
	for (int i=n;i>=2;i--)
	{
		vector<int>v;int now=i;
		for (int j=1;j<=n;j++)v.pb(now),now=now%n+1;
		for (int j=n-i+1;j>=1;j--)ans.pb(v);
	}
	assert(ans.size()<=n*(n-1));
	cout<<ans.size()<<'\n';
	for (auto x:ans)
	{
		for (auto y:x)cout<<y<<' ';
		puts("");
	}
	return 0;
}