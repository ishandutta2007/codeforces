#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	int n,x,m,p=1000000000;
	cin>>m;
	for(int i=0;i<m;i++)cin>>x,p=min(x,p);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	int ans=0;
	p+=2;
	for(int i=1;i<=n;i++){
		if(i%p!=0&&i%p!=p-1)ans+=a[i];
	}
	cout<<ans;
	return 0;
}