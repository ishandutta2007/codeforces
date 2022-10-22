#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[100005],l,ans=0;
	cin>>n>>m;
	ans+=n-1;
	for(int i=0;i<m;i++){
		cin>>l;ans+=l-1;
		for(int j=1;j<=l;j++)cin>>a[j];
		sort(a+1,a+l+1);
		int k=0;
		while(k+1==a[k+1]&&k<l)k++;
		if(k)ans-=(k-1)*2;
	}
	cout<<ans;
	return 0;
}