#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll x,a[100005],n,t1;
	cin>>x;
	for(int i=1;i<=x;i++){
		cin>>t1;
		if(t1!=0)a[++n]=t1;
	}
	if(n>126){
		cout<<3;return 0;
	}
	int l[150][150],d[150][150];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			l[i][j]=200;
			if((a[i]&a[j])!=0){
				l[i][j]=1;
			}
			d[i][j]=l[i][j];
		}
	}
	int ans=200;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&i!=k&&j!=k){
					ans=min(ans,l[i][j]+d[i][k]+d[k][j]);
					l[i][j]=min(l[i][j],l[i][k]+l[k][j]);
				}	
			}
		}
	if(ans==200)cout<<-1;else cout<<ans;
	return 0;
}