#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll n,x,ans=0,j=0,o=0;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&x);ans+=x/2;
		if(x&1){
			if(i&1)j++;else o++;
		}
	}
	cout<<ans+min(j,o);
	return 0;
}