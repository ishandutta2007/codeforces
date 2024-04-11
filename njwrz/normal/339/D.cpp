#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int n,a[300005],l[300005],r[300005];
bool f[300005];
void cl(int p){
	if(f[p]==0){
		a[p]=a[p*2]|a[p*2+1];
	}else a[p]=a[p*2]^a[p*2+1];
	if(p==1)return ;
	cl(p/2);
}
int main(){
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=(1<<n);i++)scanf("%d",&a[(1<<n)+i-1]),l[(1<<n)+i-1]=r[(1<<n)+i-1]=i,f[(1<<n)+i-1]=1;
	for(int i=(1<<n)-1;i>=1;i--)l[i]=l[(i<<2)+1],r[i]=r[(i<<1)+1],f[i]=1-f[i*2];
	for(int i=(1<<n)-1;i>=1;i--){
		if(f[i]==0){
			a[i]=(a[i*2]|a[i*2+1]);
		}else a[i]=(a[i*2]^a[i*2+1]);
	}
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		a[(1<<n)+x-1]=y;
		cl(((1<<n)+x-1)>>1);
		printf("%d\n",a[1]);
	}
	return 0;
}