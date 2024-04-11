#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

#define N 80000
#define M 300

int n,m,a[N],f[N][M][4];

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(f[0],0x88,sizeof f[0]);
	f[0][0][0]=f[0][0][1]=f[0][0][2]=f[0][0][3]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			int s=(j==1 || j==m)?1:2;
			f[i][j][0]=max(f[i-1][j][0],f[i-1][j-1][3])-s*a[i];
			f[i][j][1]=max(f[i][j][0],f[i-1][j][1]);
			f[i][j][2]=max(f[i-1][j][2],f[i-1][j-1][1])+s*a[i];
			f[i][j][3]=max(f[i][j][2],f[i-1][j][3]);
			if (j!=1 && j!=m){
				f[i][j][1]=max(f[i][j][1],f[i-1][j-1][1]);
				f[i][j][3]=max(f[i][j][3],f[i-1][j-1][3]);
			}
		}
	printf("%d\n",max(f[n][m][1],f[n][m][3]));
	
	return 0;
}