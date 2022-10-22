#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,a[101],n,ans=0;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(i=0;i<n;i+=2){
		ans+=a[i+1]-a[i];
	}
	cout<<ans;
	return 0;
}