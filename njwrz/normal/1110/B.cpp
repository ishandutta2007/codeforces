#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001];
int main(){
	int i,n,m,k,ans;
	cin>>n>>m>>k;ans=n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n-1;i++){
		b[i]=a[i+1]-a[i]-1;
	}
	sort(b,b+n-1);
	for(i=0;i<n-k;i++)ans+=b[i];
	cout<<ans;
	return 0;
}