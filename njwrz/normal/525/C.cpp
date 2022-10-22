#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005],n;
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	ll last=-1,ans=0;
	for(ll i=1;i<n;i++){
		if(a[i]-a[i+1]<2){
			if(last==-1){
				last=a[i+1];i++;
			}else{
				ans=ans+last*a[i+1];i++;last=-1;
			}
		}
	}
	cout<<ans;
	return 0;
}