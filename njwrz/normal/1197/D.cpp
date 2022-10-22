#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[300005],qz[300005],ans[300005];
ll zero=0;
int main(){
	ll n,m,k,maxi=0;
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++)cin>>a[i],qz[i]=qz[i-1]+a[i];
	for(ll i=1;i<=n;i++){
		if(i>m){
			ans[i]=max(zero,qz[i]-qz[i-m]-k+ans[i-m]);
		}
		for(ll j=i;j>=1&&j>=i-m+1;j--){
			ans[i]=max(ans[i],qz[i]-qz[j-1]-k);
		}
		maxi=max(maxi,ans[i]);
	}
	cout<<maxi;
	return 0;
}