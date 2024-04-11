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

const int M=3e5+10;
int ans,n,a[M],cnt[M],sum[M],cnt1[M],cnt0[M];

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		for (int j=0;j<64;j++)
			if ((1ll<<j)&a[i])cnt[i]++;
	}for (int i=1;i<=n;i++)
		sum[i]=sum[i-1]+cnt[i];
	cnt0[0]=1;
	for (int i=1;i<=n;i++)
	{
		cnt0[i]=cnt0[i-1],cnt1[i]=cnt1[i-1];
		if (sum[i]&1)cnt1[i]++;
		else cnt0[i]++;
		if (sum[i]&1)ans+=cnt1[i-1];
		else ans+=cnt0[i-1];int maxn=0;
		for (int j=i;j>=max(1ll,i-64);j--)
		{
			maxn=max(maxn,cnt[j]);
			if (maxn*2>sum[i]-sum[j-1]&&((sum[i]-sum[j-1])&1)==0)
				ans--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*

*/