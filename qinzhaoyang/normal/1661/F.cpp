#include <stdio.h>
#include <bits/stdc++.h>
using ll=long long;
ll n,m,a[200010],s,ans;
std::map<ll,ll>K;
ll get(ll x,ll y){
	ll c1=y-x%y,c2=x%y;
	return(x/y)*(x/y)*c1+(x/y+1)*(x/y+1)*c2;
}
int main() {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	scanf("%lld",&m);
	for(int i=n;i;i--){
		a[i]-=a[i-1],s+=a[i]*a[i];
		for(int k=2,j;k<=a[i];k=j+1){
			j=a[i]/(a[i]/k);
			K[get(a[i],k-1)-get(a[i],k)]++;
			if(k<j)K[get(a[i],k)-get(a[i],k+1)]+=j-k;
		}
	}
	if(s<=m)return puts("0"),0;
	for(auto it=--K.end();;it--){
		ll x=it->first,y=it->second;
		if(s-x*y<=m){
			ans+=(s-m+x-1)/x;
			break;
		}
		s-=x*y,ans+=y;
	}
	return printf("%lld\n",ans),0;
}