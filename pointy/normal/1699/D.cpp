// Author: Little09
// Problem: CF1699D Almost Triple Deletions
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1699D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=5005;
int n,m; 
int a[N],dp[N],cnt[N],mx;

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}

void work()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	dp[1]=1;
	for (int i=2;i<=n;i++) dp[i]=-1e9;
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<=n;j++) cnt[j]=0;
		mx=0;
		for (int j=i-1;j>=1;j--)
		{
			int len=i-j-1;
			if (len%2==0&&mx<=len/2&&a[j]==a[i]) dp[i]=max(dp[i],dp[j]+1);
			cnt[a[j]]++;
			mx=max(mx,cnt[a[j]]);
		}
		if ((i-1)%2==0&&mx<=(i-1)/2) dp[i]=max(dp[i],1);
	}
	for (int j=1;j<=n;j++) cnt[j]=0;
	mx=0;
	int ans=0;
	for (int j=n;j>=1;j--)
	{
		int len=n-j;
		if (len%2==0&&mx<=len/2) ans=max(ans,dp[j]);
		cnt[a[j]]++;
		mx=max(mx,cnt[a[j]]);
	}
	cout << ans << endl;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}