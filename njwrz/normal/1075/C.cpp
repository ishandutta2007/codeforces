#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main(){
	int x,y,z,lb=0,n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		if(x==1){
			b[++lb]=y;
		}
	}
	sort(a+1,a+n+1);
	sort(b+1,b+lb+1);
	a[n+1]=1000000000;
	int ans=n+m;
	for(int i=1;i<=n+1;i++){
		ans=min(ans,(int)(i+lb-(lower_bound(b+1,b+lb+1,a[i])-b)));
	}
	cout<<ans;
	return 0;
}