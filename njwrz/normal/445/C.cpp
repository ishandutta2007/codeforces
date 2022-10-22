#include <bits/stdc++.h>
using namespace std;
int l,r,q,a[505],n,m;
double ans;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		cin>>l>>r>>q;
		ans=max(ans,1.0*(a[l]+a[r])/q);
	}
	printf("%.15f",ans);
	return 0;
}