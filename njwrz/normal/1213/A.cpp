#include <bits/stdc++.h> 
#define ll long long
using namespace std;
int main(){
	ll ans=0,n,a[105];
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	ll t=0;
	for(int i=0;i<n;i++)if(a[i]%2)t++;
	ans=t;
	t=0;
	for(int i=0;i<n;i++)if(a[i]%2==0)t++;
	cout<<min(ans,t);
	return 0;
}