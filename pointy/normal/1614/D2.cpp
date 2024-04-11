#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e5+5,M=2e7;

ll a[M+5],b[M+5],dp[M+5];
const ll inf=1e18;
int n;

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
const int MAXN=M;
int p[M+5],v[M+5],cnt;
void init() 
{
    v[1]=1,cnt=0;
    for (int i=2;i<=MAXN;++i) 
	{
        if (!v[i]) p[++cnt]=i;
        for (int j=1;j<=cnt&&i*p[j]<=MAXN;++j) 
		{
            v[i*p[j]]=1;
            if (i%p[j]==0) break; 
        }
    }
}

int main()
{
	n=read();
	init();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		a[x]++;
	}
	for (int i=1;i<=cnt;i++)
	{
		for (int j=M/p[i];j>=1;j--)
		{
			a[j]+=a[j*p[i]];
		}
	}
	ll ans=0;
	for (ll i=2;i<=M;i++) dp[i]=-inf;
	dp[1]=a[1];
	for (ll i=1;i<=M;i++)
	{
		for (int k=1;i*p[k]<=M;k++)
		{
			int j=i*p[k];
			dp[j]=max(dp[j],dp[i]+a[j]*(j-i));
		}
		ans=max(ans,dp[i]);
	}
	cout << ans;
	return 0;
}