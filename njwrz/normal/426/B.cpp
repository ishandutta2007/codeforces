#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[101][101];
bool check(int x){
	if(x&1)return 0;
	for(int i=1;i<=x/2;i++){
		for(int j=1;j<=m;j++)if(a[i][j]!=a[x-i+1][j])return 0;
	}
	return 1;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>a[i][j];
	}
	while(check(n))n/=2;
	cout<<n;
	return 0;
}