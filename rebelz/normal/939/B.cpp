#include<iostream>

using namespace std;

typedef long long ll;

ll n,k;
ll a[100005];
ll ans=0,t;

int main(){
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>a[i];
		ans=max(ans,a[i]);
	}
	for(int i=1;i<=k;i++){
		if(n%a[i]<ans){
			ans=n%a[i];
			t=i;
		}
	}
	cout<<t<<' '<<n/a[t]<<endl;
	return 0;
}