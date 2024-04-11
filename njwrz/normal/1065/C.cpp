#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],b[200005];
int main(){
	ll n,k,hi=0;
	cin>>n>>k;
	for(ll i=1;i<=n;i++)cin>>a[i],hi=max(hi,a[i]);
	sort(a+1,a+n+1);
	ll last=a[1];
	for(ll i=2;i<=n;i++){
		if(a[i]!=last){
			b[a[i]]=n-i+1;
			last=a[i];
		}
	}
	ll ans=0,s=0;
	while(hi>a[1]){
		ll t=k;
		while(hi>a[1]){
			s=max(b[hi],s);
			if(t>=s){
				t-=s;hi--;
			}else break;
		}
		ans++;
	}
	cout<<ans;
	return 0;
}