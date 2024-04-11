#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005],b[100005];
int main(){
	ll n,p,l,r;
	cin>>n>>p;
	for(ll i=1;i<=n;i++){
		cin>>l>>r;
		a[i]=r/p-(l-1)/p;
		b[i]=r-l+1;
	}
	a[n+1]=a[1];b[n+1]=b[1];
	double ans=0;
	for(ll i=1;i<=n;i++){
		ll t=a[i]*b[i+1]+
		a[i+1]*b[i]-a[i]*a[i+1];
		ans+=(double)t*2000.0/b[i]/b[i+1];
	}
	printf("%.10f",ans);
	return 0;
}