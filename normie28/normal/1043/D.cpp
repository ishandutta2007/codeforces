#include<bits/stdc++.h>
using namespace std;

const int N=1e5+11,M=12;
int a[M][N],b[M][N],n,m,h[N];

bool chk(int x,int y){
	int z=a[1][b[1][x]+y],j;
	if(!z)return 0;
	for(j=2;j<=m;++j)
		if(a[j][b[j][x]+y]!=z)return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int i,j,x,y,z;
	long long an=0;
	for(i=1;i<=m;++i){
		for(j=1;j<=n;++j)
			cin>>x,b[i][a[i][j]=x]=j;
	}
	y=0;
	for(i=1;i<=n;++i){
		x=a[1][i];
		--y,y=max(y,0);
		while(chk(x,y)){
			++y;
		}
		an+=y;
	}
	cout<<an<<endl;
}