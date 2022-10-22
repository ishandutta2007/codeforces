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

const int inf=1e18;
const int M=530;
int n,dp[M];
vector<int>ans;

signed main()
{
	n=read();
	for (int i=1;i<512;i++)dp[i]=inf;
	while(n--)
	{
		int x=read();
		for (int j=0;j<512;j++)
			if (dp[j]<=x)dp[j^x]=min(dp[j^x],x);
	}
	for (int i=0;i<512;i++)
		if (dp[i]!=inf)ans.pb(i);
	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();i++)
		cout<<ans[i]<<' ';
	return 0;
}