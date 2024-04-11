#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	ll a[1005],n,ans=0;
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++){
		ans+=a[i]-a[i-1]-1;
	}
	cout<<ans;
	return 0;
}