#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll a[105][105];
int main(){
	ll x,y,n,m,k;
	cin>>n>>m>>k>>x>>y;
	ll t,s;
	if(n!=1){
		t=k/((n*2-2)*m);s=k%((n*2-2)*m);
	}else t=k/m,s=k%m;
	for(int i=1;i<=m;i++)a[1][i]=a[n][i]=t;
	for(int i=2;i<n;i++)for(int j=1;j<=m;j++)a[i][j]=t*2;
	bool f=(s!=0);
	for(int i=1;i<=n&&f;i++){
		for(int j=1;j<=m&&f;j++){
			a[i][j]++;
			s--;
			if(!s){
				f=0;
			}
		}
	}
	for(int i=n-1;i>=2&&f;i--){
		for(int j=1;j<=m&&f;j++){
			a[i][j]++;
			s--;
			if(!s){
				f=0;
			}
		}
	}
	ss:
	ll ma=0,mi=k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ma=max(ma,a[i][j]);
			mi=min(mi,a[i][j]);
		}
	}
	cout<<ma<<'\n'<<mi<<'\n'<<a[x][y];
	return 0;
}