#include<bits/stdc++.h>

using namespace std;

#define N 26
int n,sum,a[N*2],w[2][N];
bitset<N*50000> f[N*2][N];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n*2;++i) scanf("%d",a+i);
	sort(a+1,a+n*2+1);
	w[0][1]=a[1]; w[1][n]=a[2];
	f[2][0][0]=1;
	for (int i=3;i<=n*2;++i){
		sum+=a[i];
		for (int j=0;j<n;++j){
			f[i][j]|=f[i-1][j];
			if (j) f[i][j]|=f[i-1][j-1]<<a[i];
		}
	}
	for (int i=sum/2;i;--i){
		if (f[n*2][n-1][i]){
			int xb1=n+1,xb2=0;
			for (int j=n*2,u=n-1,v=i;j>2;--j){
				if (f[j-1][u][v]){
					w[1][++xb2]=a[j];
				}
				else{
					w[0][--xb1]=a[j];
					--u; v-=a[j];
				}
			}
			break;
		}
	}
	for (int i:{0,1}){
		for (int j=1;j<=n;++j) printf(j==n?"%d\n":"%d ",w[i][j]);
	}
	
	return 0;
}