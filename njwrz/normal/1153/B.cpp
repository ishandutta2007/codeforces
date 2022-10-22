#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int main(){
	int n,m,h;
	cin>>n>>m>>h;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)a[i][j]=h;
	}
	for(int i=1;i<=m;i++){
		cin>>h;
		for(int j=1;j<=n;j++){
			a[j][i]=min(a[j][i],h);
		}
	}
	for(int i=1;i<=n;i++){
		cin>>h;
		for(int j=1;j<=m;j++){
			a[i][j]=min(a[i][j],h);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>h;
			if(!h)a[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cout<<a[i][j]<<' ';
		cout<<'\n';
	}
	return 0;
}