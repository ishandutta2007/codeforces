#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	double a[100001],ans=0,x=0,k,m;
	int i,j;
	cin>>n>>k>>m;
	for(i=0;i<n;i++){
		cin>>a[i];x+=a[i];
	}
	sort(a,a+n);
	for(i=0;i<n;i++){
		x+=min(k*(n-i),m);
		ans=max(ans,x/(n-i));
		x-=min(k*(n-i),m);
		m--;
		x-=a[i];
		if(m<0)break;
	}
	printf("%.20f",ans);
	return 0;
}