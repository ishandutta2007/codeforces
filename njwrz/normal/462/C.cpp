#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[300005],ans=0;
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)ans=ans+(i+1)*a[i];
	cout<<ans-a[n];
	return 0;
}