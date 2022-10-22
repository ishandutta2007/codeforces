#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[105],n,l[105],r[105],ans=0;
	cin>>n;
	char c;
	for(int i=1;i<=n;i++){
		cin>>c;
		a[i]=c-'0';ans+=a[i];
	}
	for(int i=1;i<=n;i++)cin>>r[i]>>l[i];
	for(int i=1;i<=10000;i++){
		int t=0;
		for(int j=1;j<=n;j++){
			if(i>=l[j]&&l[j]%r[j]==i%r[j]){
				a[j]=1-a[j];
			}
			t+=a[j];
		}
		ans=max(ans,t);
	}
	cout<<ans;
	return 0;
}