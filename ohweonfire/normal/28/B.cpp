#include <iostream>
using namespace std;
bool g[102][102];
int p[102];
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){cin>>p[i];}
	for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			g[i][i]=true;
			if(i-x>0)g[i-x][i]=g[i][i-x]=true;
			if(i+x<=n)g[i+x][i]=g[i][i+x]=true;
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{g[i][j]|=(g[i][k]&&g[k][j]);}
	for(int i=1;i<=n;i++)if(!g[i][p[i]]){cout<<"NO";return 0;}
	cout<<"YES";
	return 0;
}