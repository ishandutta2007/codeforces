#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll a[500005],l[500005];
int main(){
	ll n,q=0,ans=0;cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		l[i]=l[i-1]+a[i];
	}
	if(l[n]%3){
		cout<<0;return 0;
	}
	for(int i=1;i<n;i++){
		if(l[i]*3==l[n]*2)ans+=q;
		if(l[i]*3==l[n])q++;
	}
	cout<<ans;
	return 0;
}