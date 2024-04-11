#include <bits/stdc++.h>
using namespace std;
int n,m,a[55][55],b[55][55];
vector <int> v1,v2;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>a[i][j];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1]){
				b[i][j]=1;
				b[i+1][j]=1;
				b[i][j+1]=1;
				b[i+1][j+1]=1;
				v1.push_back(i);v2.push_back(j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]!=b[i][j]){
				cout<<-1;return 0;
			}
		}
	}
	cout<<v1.size()<<'\n';
	for(int i=0;i<v1.size();i++){
		cout<<v1[i]<<' '<<v2[i]<<'\n';
	}
	return 0;
}