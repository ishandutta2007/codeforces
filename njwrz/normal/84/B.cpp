#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a[100005];
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long l=1,last=a[1],ans=0;
	for(int i=2;i<=n;i++){
		if(a[i]!=last){
			last=a[i];
			ans=ans+l*(l+1)/2;l=1;
		}else l++;
	}
	cout<<ans+l*(l+1)/2;
	return 0;
}