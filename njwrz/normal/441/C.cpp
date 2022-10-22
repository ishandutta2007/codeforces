#include <bits/stdc++.h>
using namespace std;
int f[305][305];
int main(){
	int n,m,k,fx=1;
	cin>>n>>m>>k;
	int x=1,y=1;
	for(int i=1;i<k;i++){
		cout<<"2 "<<x<<' '<<y;
		f[x][y]=1;
		if(!f[x][y+1]&&y+1<=m){
			cout<<' '<<x<<' '<<y+1<<'\n';
			f[x][y+1]=1;
		}else if(!f[x][y-1]&&y-1>=1){
			cout<<' '<<x<<' '<<y-1<<'\n';
			f[x][y-1]=1;
		}else if(!f[x+1][y]&&x+1<=n){
			cout<<' '<<x+1<<' '<<y<<'\n';
			f[x+1][y]=1;
		}
		while(f[x][y]){
			y+=fx;
			if(y==m+1){
				x++;fx=-fx;y=m;
			}else if(y==0){
				x++;fx=-fx;y=1;
			}
		}
	}
	cout<<n*m-(k-1)*2<<' ';
	for(int i=0;i<n*m-(k-1)*2;i++){
		cout<<x<<' '<<y<<' ';
		y+=fx;
		if(y==m+1){
			x++;fx=-fx;y=m;
		}else if(y==0){
			x++;fx=-fx;y=1;
		}
	}
	return 0;
}