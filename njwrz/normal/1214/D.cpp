#include <bits/stdc++.h>
#define pb push_back
using namespace std;
vector <int> a[1000005],b[1000005],c[1000005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)a[i].pb(0),b[i].pb(0),c[i].pb(0);
	char x;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>x;
			if(x=='#')c[i+1][j+1]=1;
		}
	int t=0;
	a[0][1]=b[n+1][m]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(c[i][j])continue;
			a[i][j]=a[i][j-1]|a[i-1][j];
		}
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--){
			if(c[i][j])continue;
			b[i][j]=b[i][j+1]|b[i+1][j];
		}
	a[0][1]=b[n+1][m]=0;
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--){
			c[i][j]=0;
			if(a[i][j]&&b[i][j]){
				t++;c[i][j]=1;a[i][j]=1;b[i][j]=1;
			}
		}
	if(t==0){
		cout<<0;return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=a[i-1][j]+c[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]+=a[i][j-1];
		}
	}
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--){
			b[i][j]=b[i+1][j]+c[i][j];
		}
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--){
			b[i][j]+=b[i][j+1];
		}
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--){
			if(a[i][j]+b[i][j]==t+1&&c[i][j]
				&&(i!=1||j!=1)&&(i!=n||j!=m)){
				cout<<1;return 0;
			}
		}
	cout<<2;
	return 0;
}