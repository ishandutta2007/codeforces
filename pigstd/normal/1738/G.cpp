#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--)
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
inline void ckmax(int &a,int b){a=(a>b?a:b);}
inline void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=1010;
int n,a[M][M],lst[M],ans[M][M],k;
string s;

void solve()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++)
	{
		cin>>s;
		for (int j=0;j<n;j++)a[i][j+1]=(s[j]-'0'),ans[i][j+1]=0;
	}
	for (int i=1;i<=n;i++)
	{
		lst[i]=n+1;
		for (int j=n;j>=1;j--)
			if (a[j][i]==0)lst[i]=j;
	}
	for (int i=1;i<k;i++)for (int j=1;j<k-i;j++)ans[n-j+1][i]=ans[i][n-j+1]=1;
	for (int i=1;i<k;i++)
	{
		int now=n-k+i+1;
//		cerr<<i<<' '<<now<<'\n'; 
		for (int j=i;j<=n-k+i+1;j++)
		{
			int tmp=now;
			ckmin(now,lst[j]);
//			cerr<<j<<' '<<now<<'\n';
			if (j==n-k+i+1)now=i;
			for (int k=now;k<=tmp;k++)
				if (ans[k][j])return puts("NO"),void();
				else ans[k][j]=1;
			while(lst[j]<=n&&(a[lst[j]][j]==1||ans[lst[j]][j]==1))lst[j]++;
		}
//		for (int i=1;i<=n;i++)
//		{
//			for (int j=1;j<=n;j++)cerr<<ans[i][j];
//			cerr<<'\n';
//		}
	}
	for (int i=1;i<=n;i++)for (int j=1;j<=n;j++)if (ans[i][j]==0&&a[i][j]==0)return puts("NO"),void();
	puts("YES");
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)cout<<ans[i][j];
		puts("");
	}
}

signed main()
{
	WT solve();
	return 0;
}
/*
1
4 3
1110
0101
1010
0111
*/