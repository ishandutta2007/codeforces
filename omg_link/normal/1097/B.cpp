#include <stdio.h>
#include <stdlib.h>
int n,a[16];
void dfs(int i,int tot){
	tot=(tot+360)%360;
	if(i==n+1){
		if(tot==0){
			puts("YES");
			exit(0);
		}
		return;
	}
	dfs(i+1,tot+a[i]);
	dfs(i+1,tot-a[i]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1,0);
	puts("NO");
}