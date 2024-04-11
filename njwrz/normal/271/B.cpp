#include <bits/stdc++.h>
using namespace std;
int vis[200005],a[505][505];
void ss(){
	fill(vis+2,vis+200001,1);
	for(int i=2;i<=200000;i++){
		if(vis[i]){
			for(int j=i*2;j<=200000;j+=i){
				vis[j]=0;
			}
		}
	}
}
int main(){
	ss();
	int n,m,f,ans=1000000000,t;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		f=0;
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			t=a[i][j];
			while(vis[t]!=1){
				t++;f++;
			}
		}
		ans=min(ans,f);
	}
	for(int i=1;i<=m;i++){
		f=0;
		for(int j=1;j<=n;j++){
			t=a[j][i];
			while(vis[t]!=1){
				t++;f++;
			}
		}
		ans=min(ans,f);
	}
	cout<<ans;
	return 0;
}