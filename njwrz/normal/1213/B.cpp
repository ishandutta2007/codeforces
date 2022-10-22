#include <bits/stdc++.h> 
#define ll long long
using namespace std;
void voi(){
	int n;
	cin>>n;
	int ans=0,a[n+10];
	for(int i=1;i<=n;i++)cin>>a[i];
	int m=1000000000;
	for(int i=n;i>=1;i--){
		if(a[i]>m)ans++;
		m=min(m,a[i]);
	}
	cout<<ans<<'\n';
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)voi();
	return 0;
}