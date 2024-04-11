#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;

typedef long long ll;

const int N=51;

bool f[N][N];

int n,k;

ll a[N],w[N][N];

bool ok(ll v)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			f[i][j]=0;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int K=1;K<=k;K++)
			for(int j=0;j<i;j++)
				f[i][K]|=(f[j][K-1]&((w[j+1][i]&v)==v));
	return f[n][k];
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)	
			w[i][j]=w[i][j-1]+a[j];
	ll ans=0;
	for(int i=60;i>=0;i--)
		if(ok((1ll<<i)+ans))
			ans+=(1ll<<i);
	printf("%lld",ans);
}