#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005],n,d;
int main(){
	cin>>n>>d;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;return 0;
	}
	ll l=1,ans=0;
	for(ll i=3;i<=n;i++){
		while(a[i]-a[l]>d)l++;
		if(i-l>1)ans+=(i-l-1)*(i-l)/2;
	}
	cout<<ans;
	return 0;
}