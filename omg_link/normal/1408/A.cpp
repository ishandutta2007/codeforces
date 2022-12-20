#include <stdio.h>
#define MN 100

int n,a[3][MN+5],p[MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	p[0] = a[0][0];
	for(int i=1;i<n;i++){
		for(int j=0;j<3;j++){
			if(a[j][i]!=p[(i-1+n)%n]){
				if(i!=n-1){
					p[i] = a[j][i];
					break;
				}else if(a[j][i]!=p[0]){
					p[i] = a[j][i];
					break;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
		printf("%d ",p[i]);
	puts(""); 
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}