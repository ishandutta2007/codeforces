#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll ab(ll i,ll j,ll k){
	return abs(i-j)+abs(i-k)+abs(j-k);
}
int main(){
	ll a,b,c;
	ll t;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		ll ans=1e18;
		for(ll i=a-1;i<=a+1;i++){
			for(ll j=b-1;j<=b+1;j++){
				for(ll k=c-1;k<=c+1;k++){
					ans=min(ans,ab(i,j,k));
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}