#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,k,a[100005],i,l,t,s,ans=0,r,last;
	cin>>n>>k>>m;
	for(i=1;i<=k;i++)cin>>a[i];
	s=0;l=1;
	while(l<=k){
		ans++;last=l;
		t=a[l]-s;
		r=t/m*m+(t%m!=0)*m;
		while(a[l]-s<=r&&l<=k)l++;
		s+=l-last;
	}
	cout<<ans;
	return 0;
}