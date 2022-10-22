#include<bits/stdc++.h>
#define ll long long
using namespace std;
pair<ll,ll> a[100005];
ll n;
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&a[i].first,&a[i].second);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		ll t=a[i].second,p=1;
		for(int j=a[i-1].first;j<a[i].first;j++){
			t=t*4;p=p*4;
			if(t>=a[i-1].second){
				break;
			}
		}
		if(a[i-1].second>t){
			ll s=a[i-1].second-t;
			a[i].second+=s/p+(s%p!=0);
		}
	}
	if(a[n].second==1){
		cout<<a[n].first+1;return 0;
	}
	ll p=1,l=0;
	while(p<a[n].second){
		p=p*4;
		l++;
	}
	cout<<a[n].first+l;
	return 0;
}