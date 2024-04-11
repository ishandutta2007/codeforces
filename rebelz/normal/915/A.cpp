#include<iostream>

using namespace std;

int n,k;
int a[105];

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=1<<30;
	for(int i=1;i<=n;i++)
		if(k%a[i]==0)
			ans=min(ans,k/a[i]);
	cout<<ans<<endl;
	return 0;
}