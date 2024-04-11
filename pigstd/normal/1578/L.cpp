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

const int M=510;
int n,m,a[M][M],cnt[M][M],f[M][M];
string s;

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		cin>>s;
		for (int j=1;j<=m;j++)
			a[i][j]=s[j-1]=='B';
	}
	int res=0;
	for (int i=n;i>=1;i--)
		for (int j=m;j>=1;j--)
		{
			cnt[i][j]=cnt[i][j+1]+cnt[i+1][j]-cnt[i+1][j+1];
			if ((a[i][j]+cnt[i][j])&1)
				res++,cnt[i][j]++,f[i][j]=1;
		}
	for (int i=1;i<n;i++)
		for (int j=1;j<m;j++)
			if (f[i][j]&&f[n][m]&&f[i][m]&&f[n][j])res--,f[n][m]=0;
	cout<<res<<endl;
	return 0;
}
// break 