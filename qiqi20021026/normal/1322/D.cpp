#include<bits/stdc++.h>

using namespace std;

#define N 2200

int n,m,p,f[N][N<<1],a[N],b[N],c[N<<1];

void upd(int &x,int y){x=max(x,y);}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%d",a+i);
	for (int i=1;i<=n;++i) scanf("%d",b+i);
	for (int i=1;i<=n+m;++i) scanf("%d",c+i);
	memset(f,0xcf,sizeof f);
	p=m+min(n,12);
	for (int i=1;i<=p;++i) f[i][0]=0;
	for (int i=n;i;--i){
		int x=a[i];
		for (int j=n;j;--j){
			upd(f[x][j],f[x][j-1]-b[i]+c[x]);
		}
		for (int j=1;x+j<=p;++j){
			for (int k=0;k<=(n>>(j-1));++k){
				upd(f[x+j][k>>1],f[x+j-1][k]+c[x+j]*(k>>1));
			}
		}
	}
	printf("%d\n",f[p][0]);
	
	return 0;
}