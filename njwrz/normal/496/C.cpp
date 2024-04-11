#include <bits/stdc++.h>
using namespace std;
char c[105][105];
int n,m,f[105],t[105],ans;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>c[i][j];
	}
	for(int i=1;i<=m;i++){
		bool ff=1;
		for(int j=1;j<n;j++)f[j]=t[j];
		for(int j=1;j<n;j++){
			if(f[j])continue;
			if(c[j][i]<c[j+1][i]){
				f[j]=1;
			}else if(c[j][i]>c[j+1][i]){
				ans++;ff=0;break;
			}
		}
		if(ff){
			for(int j=1;j<n;j++)t[j]=f[j];
		}
	}
	cout<<ans;
	return 0;
}