#include <bits/stdc++.h>
using namespace std;
int main(){
	int x1[5005]={0},x2[5005]={0};
	int y1[5005]={0},y2[5005]={0};
    int n,m,k,x,y,z;
    cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		cin>>x>>y>>z;
		if(x==1){
			x1[y]=z;
			y1[y]=i;
		}else{
			x2[y]=z;
			y2[y]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(y1[i]<y2[j]){
				cout<<x2[j]<<' ';
			}else if(x1[i]){
				cout<<x1[i]<<' ';
			}else cout<<"0 ";
		}
		cout<<'\n';
	}
    return 0;
}