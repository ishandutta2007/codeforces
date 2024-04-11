#include <stdio.h>
const int N=7000;
int a[2][N],b[2][N],Q[N<<1],d[2][N];
int main(){
	int n; scanf("%d",&n);
	int K[2];
	for(int j=0;j<2;j++){
		scanf("%d",K+j);
		for(int i=0;i<K[j];i++)scanf("%d",&b[j][i]);
	}
	a[0][0]=2;a[1][0]=2;
	int qs=0,qe=0;
	Q[qe++]=0;Q[qe++]=1;
	while(qs<qe){
		int x = Q[qs++];
		int i=x/2;int j=x%2;
		if(a[j][i]==2){
			for(int k=0;k<K[j^1];k++){
				int ii = (i+n-b[j^1][k])%n;
				if(!a[j^1][ii]){
					a[j^1][ii]=1;
					Q[qe++]=ii<<1|(j^1);
				}
			}
		}
		else{
			for(int k=0;k<K[j^1];k++){
				int ii=(i+n-b[j^1][k])%n;
				if(!a[j^1][ii]){
					d[j^1][ii]++;
					if(d[j^1][ii]==K[j^1]){
						a[j^1][ii]=2;
						Q[qe++]=ii<<1|(j^1);
					}
				}
			}
		}
	}
	for(int j=0;j<2;j++){
		for(int i=1;i<n;i++){
			if(a[j][i]==2)printf("Lose ");
			else if(a[j][i]==1)printf("Win ");
			else printf("Loop ");
		}
		puts("");
	}
}