#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,k,a[100100],i,ans=0;
	cin>>n>>k;n%=2;
	for(i=0;i<k;i++)cin>>a[i];
	for(i=0;i<k;i++){
		a[i]%=2;
		ans+=a[i]*pow(n,k-i-1);
	}
	if(ans%2==1)cout<<"odd";else cout<<"even";
	return 0;
}