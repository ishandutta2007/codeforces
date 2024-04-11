#include <bits/stdc++.h>
using namespace std;
int a[1005][1005],n,m,r[1005],c[1005],f1[1005][1005],f2[1005][1005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>r[i];
	for(int i=1;i<=m;i++)cin>>c[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=r[i];j++)a[i][j]=1;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=c[i];j++)a[j][i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==0){
				if(!f1[i][j]){
					for(int k=j+1;k<=m;k++){
						f1[i][k]=1;
					}
				}
				if(!f2[i][j]){
					for(int k=i+1;k<=n;k++){
						f2[k][j]=1;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		int l=1;
		while(a[i][l]&&l<=m)l++;
		if(l!=r[i]+1){
			cout<<0;return 0;
		}
	}
	for(int i=1;i<=m;i++){
		int l=1;
		while(a[l][i]&&l<=n)l++;
		if(l!=c[i]+1){
			cout<<0;return 0;
		}
	}
	int ans=1;
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			if(a[i][j]==0&&f2[i][j]&&f1[i][j]){
				ans=ans*2;
				ans%=1000000007;
			}
		}
	}
	cout<<ans;
	return 0;
}