#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll po(ll p){
	if(p<3)return pow(2,p);
	return po(p/2)*po(p/2)*(1+(p%2))%1000000007;
}
int main(){
	string s;
	cin>>s;
	ll l=s.size();
	ll ans=0;
	for(ll i=0;i<l;i++){
		if(s[i]=='1'){
			ans=ans+po(i)*((po(l-i-1)*po(l-i-1))%1000000007);
			ans=ans%1000000007;
		}
	}
	cout<<ans;
	return 0;
}