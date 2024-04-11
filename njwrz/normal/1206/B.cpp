#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll x,n,ans=0,f=0,ff=0;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>x;
		if(x==0)ff=1;
		ll t1=abs(x+1),t2=abs(x-1);
		if(t1<t2){
			f--;ans+=t1;
		}else {
			ans+=t2;
		}
	}
	f=-f;
	if(f%2&&!ff){
		ans+=2;
	}
	cout<<ans;
	return 0;
}