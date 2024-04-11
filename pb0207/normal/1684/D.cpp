#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T;

int n,a[N],k;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		long long s=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),s+=a[i],a[i]+=i;
		s+=1ll*k*n;
		sort(a+1,a+n+1);
		for(int i=n;i>=n-k+1;i--)
			s-=a[i];
		printf("%lld\n",s-1ll*(k)*(k-1)/2);
	}
}