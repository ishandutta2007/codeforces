#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n,k;
ll a[200005];

int main(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	ll now=0,ans=0,tmp;
	for(int i=1;i<=n-1;i++){
		tmp=(a[i]+now)/k;
		if(now>0)
			tmp=max(tmp,(now-1)/k+1);
		a[i]-=tmp*k-now,ans+=tmp;
		now=max(a[i],0ll);
	}
	if(a[n]+now>0)
		cout<<ans+(a[n]+now-1)/k+1<<endl;
	else
		cout<<ans<<endl;
	return 0;
}