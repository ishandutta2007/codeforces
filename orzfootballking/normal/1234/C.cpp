#include <bits/stdc++.h>
using namespace std;
int q[3][200005][2],n,a[200005][2];
int dfs(int de,int l,int h){
	if(q[de][l][h])return q[de][l][h];
	if(l==n+1){
		if(h==1&&de==0)return 2;
		return 1;
	}
	if(a[l][h]==1){
		if(de!=0){
			q[de][l][h]=1;
			return 1;
		}else {
			q[de][l][h]=dfs(0,l+1,h);
			return q[de][l][h];
		}
	}else{
		if(de!=0){
			q[de][l][h]=dfs(0,l+1,h);
			return q[de][l][h];
		}else{
			q[de][l][h]=dfs(1,l,1-h);
			return q[de][l][h];
		}
	}
}
int main(){
	int t;
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>n;
		char x;
		for(int i=1;i<=n;i++){
			cin>>x;
			if(x<'3')a[i][0]=1;else a[i][0]=2;
		}
		for(int i=1;i<=n;i++){
			cin>>x;
			if(x<'3')a[i][1]=1;else a[i][1]=2;
		}
		for(int i=1;i<=n+1;i++){
			q[0][i][1]=q[1][i][1]=q[2][i][1]=0;
			q[0][i][0]=q[1][i][0]=q[2][i][0]=0;
		}
		if(dfs(0,1,0)==2)puts("YES");else puts("NO");
	}
	return 0;
}