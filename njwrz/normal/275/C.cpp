#include <bits/stdc++.h>
using namespace std;
int a[100005],ans[100005],len;
int main(){
	int n,k,t;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	len=1;ans[1]=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]%k!=0){
			ans[++len]=a[i];continue;
		}
		t=lower_bound(ans+1,ans+len,a[i]/k)-ans;
		if(ans[t]!=a[i]/k){
			ans[++len]=a[i];
		}
	}
	cout<<len;
	return 0;
}