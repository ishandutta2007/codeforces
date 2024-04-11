#include <bits/stdc++.h>
using namespace std;
int a[100005],q[100005];
int main(){
	string s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	q[0]=a[0];
	for(int i=1;i<n;i++)q[i]=q[i-1]+a[i];
	cin>>s;
	int ans=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1')ans+=a[i];
	}
	int t=0;
	for(int i=n-1;i>=0;i--){
		if(s[i]=='1'){
			ans=max(ans,t+q[i]-a[i]);
			t+=a[i];
		}
	}
	cout<<ans;
	return 0;
}