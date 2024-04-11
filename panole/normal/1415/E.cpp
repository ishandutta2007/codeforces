#include<bits/stdc++.h>
using namespace std;

const long long inf=1000000000000000000ll;
long long ans;
int n,k,a[500010];

long long calc(int p)
{
	long long sum=0,ans=0;
	if (p>n) return -inf;
	for (int i=p+1; i<=n; i++) ans+=1ll*a[i]*(i-p),sum+=a[i];
	if (!p) return ans-sum;
	int po=p+1,pp=(p%k==0?k:p%k);
	for (int i=1; i<=pp; i++) sum+=a[--po];
	for (int i=1,lim=(po-1)/k; i<=lim; i++)
	{
		ans+=sum;
		for (int j=1; j<=k; j++) sum+=a[--po];
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&k),k++;
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	long long sum=0; int p=0;
	for (int i=n; i; i--)
	{
		sum+=a[i];
		if (sum<0) {p=i; break;}
	}
	ans=max(calc(p),calc(p+1));
	printf("%lld\n",ans);
	return 0;
}