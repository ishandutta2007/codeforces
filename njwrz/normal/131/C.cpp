#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll zh(ll a,ll b){
	if(b*2>a)b=a-b;
	ll l=a,re=1;
	for(ll i=1;i<=b;i++){
		re=re*(a-b+i)/i;
	}
	return re;
}
int main(){
	ll a,b,c,ans=0;
	cin>>a>>b>>c;
	for(ll i=4;i<=c-1;i++){
		if(a<i||b<c-i)continue;
		ans+=zh(a,i)*zh(b,c-i);
	}
	cout<<ans;
	return 0;
}