#include <iostream>
using namespace std;
int a[102],b[102];
bool can(int x,int y){
	 if(a[x]>a[y]&&a[x]<b[y])return true;
	 if(b[x]>a[y]&&b[x]<b[y])return true;
	 return false;
}
bool adj[102][102];
int q,n;
int main(){
	cin>>q;
	while(q--){
			   int type;
			   cin>>type;
			   if(type==1){n++;cin>>a[n]>>b[n];}
			   else{
			   		
			   		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(can(i,j))adj[i][j]=true;
			   		for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)
			   		for(int j=1;j<=n;j++)if(adj[i][k]&&adj[k][j])adj[i][j]=true;
					int x,y;
					cin>>x>>y;
					if(adj[x][y])cout<<"YES\n";else cout<<"NO\n";
				}
	}
	return 0;
}