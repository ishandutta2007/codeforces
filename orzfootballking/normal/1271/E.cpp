#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
bool check(ll mid){
	if(mid==n)return 1>=k;
	ll r=mid+1,s=2,t=mid;bool f=0;
	if(mid&1){
		r--;s--;f=1;
	}
	while(r*2+1<=n){
		r=r*2+1;
		s=s*2+2-f;t=t*2;
	} 
	t=t*2;
	s=s+max(0ll,n-t+1);
	return (s>=k);
}
int main(){
	cin>>n>>k;
	ll l=1,r=n;
	while(r-l>5){
		ll mid=(l+r)>>1;if(mid&1)mid++;
		if(check(mid)){
			l=mid;
		}else r=mid-1;
	}
	for(ll i=r;i>=l;i--){
		if(check(i)){
			cout<<i;return 0;
		}
	}
	return 0;
}