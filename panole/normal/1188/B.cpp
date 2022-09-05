#include<bits/stdc++.h>
using namespace std;

int n,a[300010],p,k;
long long ans;

int main()
{
	scanf("%d%d%d",&n,&p,&k),ans=0;
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for (int I,i=1; i<=n; i++)
	{
		I=i;
		while (I<n&&a[I+1]==a[i]) I++;
		if (2ll*a[i]*(2ll*a[i]*a[i]%p)%p!=k) ans-=(1ll*(I-i+1)*(I-i)/2);
		i=I;
	}
	for (int i=1; i<=n; i++)
	{
		a[i]=(1ll*a[i]*a[i]%p*a[i]%p*a[i]%p)-(1ll*a[i]*k%p);
		if (a[i]<0) a[i]+=p;
	}
	sort(a+1,a+1+n);
	for (int i=1,I; i<=n; i++)
	{
		I=i;
		while (I<n&&a[I+1]==a[i]) I++;
		ans+=(1ll*(I-i+1)*(I-i)/2);
		i=I;
	}
	printf("%I64d\n",ans);
	return 0;
}