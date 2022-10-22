#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,i,j,a[101],m=0,ans=0,x;
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>a[i];m=max(m,a[i]);
	}
	for(i=k;i<=m;i++){
		x=0;
		for(j=0;j<n;j++)x+=a[j]/i;
		ans=max(ans,x*i);
	}
	cout<<ans;
	return 0;
}