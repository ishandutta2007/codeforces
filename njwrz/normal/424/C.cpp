#include <bits/stdc++.h>
using namespace std;
int n,a[1000005],p[1000005],t;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],p[i]=p[i-1]^i;
	int ans=0;
	for(int i=1;i<=n;i++)ans^=a[i];
	for(int i=2;i<=n;i++){
		t=n-n%i;
		if((t/i)%2){
			ans^=p[i-1];
		}
		ans^=p[n%i];
	}
	cout<<ans;
	return 0;
}