#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,s;
ll ans[200020];
int main()
{
	cin>>n>>k>>s;
	if (s<k||k*(n-1)<s) return 0&puts("NO");
	ll cnt=0,cur=1,t=s/k,tt=s%k;
	if (tt&&t+2>n) return 0&puts("NO");
	puts("YES");
	if (tt%2==1)
	{
		k-=tt;
		while (tt--) ans[++cnt]=cur=(cur==1?t+2:1);
		while (k--) ans[++cnt]=cur=(cur==t+2?2:t+2);
		for (int i=1;i<=cnt;i++) printf("%I64d ",ans[i]);
		return 0;
	}
	k-=tt;
	while (tt--) ans[++cnt]=cur=(cur==1?t+2:1);
	while (k--) ans[++cnt]=cur=(cur==1?t+1:1);
	for (int i=1;i<=cnt;i++) printf("%I64d ",ans[i]);
	return 0;
}