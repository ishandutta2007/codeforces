#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,ll,a,t[100001],l[100001],i,last;
	cin>>n>>ll>>a;
	for(i=0;i<n;i++)cin>>t[i]>>l[i];
	last=-1;int ans=0;
	for(i=0;i<n;i++){
		ans+=(t[i]-last-1)/a;
		last=t[i]+l[i]-1;
	}
	ans+=(ll-1-last)/a;
	cout<<ans;
	return 0;
}