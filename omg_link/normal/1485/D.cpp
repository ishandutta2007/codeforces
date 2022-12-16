#include <stdio.h>
#define MN 500

int a[MN+5][MN+5];

int main(){
	int n,m,b[17];
	for(int i=1;i<=16;i++){
		for(int j=1;j<=100;j++){
			if((720720-j*j*j*j)%i==0){
				b[i] = 720720-j*j*j*j;
				break;
			}
		}
	}
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d%c",(i+j)&1?720720:b[a[i][j]]," \n"[j==m]);
		}
	}
}