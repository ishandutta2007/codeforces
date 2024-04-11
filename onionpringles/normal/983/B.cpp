#include <bits/stdc++.h>
using namespace std;
int a[5000][5000],b[5000];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",b+i);
	}
	for(int i=n;i--;)for(int j=i;j<n;j++){
		if(i==j)a[i][j]=b[i];
		else a[i][j]=a[i][j-1]^a[i+1][j];
	}
	for(int j=0;j<n;j++)for(int i=j;i--;){
		a[i][j]=max(a[i][j],a[i+1][j]);
	}
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)a[i][j]=max(a[i][j],a[i][j-1]);
	int q;scanf("%d",&q);
	for(int i=0;i<q;i++){
		int x,y;scanf("%d%d",&x,&y);x--;y--;
		printf("%d\n",a[x][y]);
	}
}