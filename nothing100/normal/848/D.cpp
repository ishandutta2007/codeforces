#include<bits/stdc++.h>
#define LL long long
#define mo 1000000007
using namespace std;
int n,m,f[60][60],g[60][60],INV[60];
void get(int x,int y){
	for (int i=0;i<x;i++)
	for (int j=y+1;j<=n;j++) g[x][y]=(g[x][y]+1LL*f[i][y]*f[x-1-i][j]*2)%mo;
	for (int i=0;i<x-1-i;i++) g[x][y]=(g[x][y]+1LL*f[i][y]*f[x-1-i][y]*2)%mo;
	if ((x-1)%2==0){
		g[x][y]=(g[x][y]+1LL*f[(x-1)/2][y]*f[(x-1)/2][y])%mo;
	}
}
int main(){
	INV[1]=1;
	for (int i=2;i<51;i++) INV[i]=1ll*(mo-mo/i)*INV[mo%i]%mo;
	scanf("%d%d",&n,&m);
	f[0][1]=1;
	for (int i=1;i<=n;i++)
	for (int j=0;j<=n+1;j++){
		get(i,j);
		for (int k=n;k>=0;k--)
		for (int l=0;l<=n+1;l++){
			int tmp=f[k][l];
			for (int h=1;k+h*i<=n&&l+h*j<=n+1;h++){
				tmp=1LL*tmp*(g[i][j]+h-1)%mo*INV[h]%mo;
				f[k+i*h][l+j*h]=(f[k+i*h][l+j*h]+tmp)%mo;
			}
		}
	}
	printf("%d\n",f[n][m]);
}