#include<bits/stdc++.h>
using namespace std;
long long n,a[300001],ans=0,i;
int main(){
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(i=0;i<n/2;i++){
		ans+=pow(a[i]+a[n-i-1],2);
	}
	cout<<ans;
	return 0;
}