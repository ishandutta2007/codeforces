#include<bits/stdc++.h>
using namespace std;
int a[2005],b[2005],c[2005],t[2005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		if(a[1]>b[i]){
			c[i]=b[i]+m-a[1];
		}else{
			c[i]=b[i]-a[1];
		}
	}
	sort(a+1,a+n+1,greater<int>());
	sort(b+1,b+n+1,greater<int>());
	int ans=2147483647;
	for(int i=1;i<=n;i++){
		int l=1;
		while(a[l]+c[i]>=m&&l<=n){
			l++;
		}
		for(int j=l;j<=n;j++){
			t[j-l+1]=a[j]+c[i];
		}
		for(int j=n-l+2;j<=n;j++){
			t[j]=a[j-n+l-1]+c[i]-m;
		}
		bool f=1;
		for(int j=1;j<=n;j++){
			if(t[j]!=b[j]){
				f=0;break;
			}
		}
		if(f)ans=min(ans,c[i]);
	}
	cout<<ans;
	return 0;
}