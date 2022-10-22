#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll n,ans=1,i,t;
	cin>>n;t=n;
	for(i=2;i*i<=t;i++){
		if(n%i==0){
			ans*=i;
			while(n%i==0)n/=i;
		}
	}
	ans*=n;
	cout<<ans;
	return 0;
}