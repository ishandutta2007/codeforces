#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[100001],i;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	sort(a,a+n,greater<int>());
	if(a[0]>=a[1]+a[2]){
		cout<<"NO";return 0;
	}
	cout<<"YES"<<endl;
	int ans[100001];
	int mid=n/2;
	if(n%2==0)mid--; 
	ans[mid]=a[0];
	int l=-1,si=1;
	for(i=1;i<n;i++){
		l=-l;
		ans[mid+si*l]=a[i];
		if(l==-1)si++;
	} 
	for(i=0;i<n;i++)cout<<ans[i]<<" ";
	return 0;
}