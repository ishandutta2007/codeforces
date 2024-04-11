#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

int n,a[N];

ll pre[N][31],suf[N][31];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=30;j++)
			pre[i][j]|=pre[i-1][j]|((a[i]>>j)&1);
	for(int i=n;i>=1;i--)
		for(int j=0;j<=30;j++)
			suf[i][j]|=suf[i+1][j]|((a[i]>>j)&1);
	ll ans=-1;
	int pos=0;
	for(int i=1;i<=n;i++)
	{
		ll x=a[i];
		for(int j=0;j<=30;j++)
			if((pre[i-1][j]||suf[i+1][j])&&((a[i]>>j)&1))
				x-=1ll<<j;
		if(x>ans)
			ans=x,pos=i;
	}
	printf("%d ",a[pos]);
	for(int i=1;i<=n;i++)
		if(i!=pos)
			printf("%d ",a[i]);
}