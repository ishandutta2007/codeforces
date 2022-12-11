#include<bits/stdc++.h> 
using namespace std;
int n,i,h[10][1000010],g[1000010],f[1000010];
int l,r,k,j,T;
int main(){
	f[0]=g[0]=1;
	for(int i=1;i<=1000000;i++){
		if(i<10)f[i]=g[i]=i;
		else f[i]=f[i/10]*max(1,i%10),g[i]=g[f[i]];
		for(j=1;j<=9;j++)
			h[j][i]=h[j][i-1];
		h[g[i]][i]++;
	}
	scanf("%d",&T); 
	while(T--){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",h[k][r]-h[k][l-1]);
	}
	
}