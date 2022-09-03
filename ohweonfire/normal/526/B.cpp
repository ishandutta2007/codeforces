#include <bits/stdc++.h>
using namespace std;
const int maxn=4444;
int a[maxn],N,n,mx[maxn];
int main()
{
	cin>>N;
	n=(1<<N+1)-1;
	for(int i=2;i<=n;i++)
		cin>>a[i];
	long long ans=0;
	for(int i=n;i;--i)
	{
		mx[i]=max(mx[i<<1]+a[i<<1],mx[i<<1|1]+a[i<<1|1]);
		ans+=abs(mx[i<<1]+a[i<<1]-mx[i<<1|1]-a[i<<1|1]);
	}
	cout<<ans<<endl;
	return 0;
}