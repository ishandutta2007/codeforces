#include <stdio.h>
#include <algorithm>
#define MN 2000

int n,a[MN*2+5],mx[2*MN+5];
int f[MN*2+5][MN*2+5][2];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++){
		scanf("%d",&a[i]);
		mx[i] = std::max(mx[i-1],a[i]);
	}
	f[0][0][0] = 1;
	f[0][0][1] = 1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			f[i][j][0] = 0;
			f[i][j][1] = 0;
		}
	for(int l=1;l<=2*n;l++){
		for(int i=0;i<=l;i++){
			int j=l-i;
			if(i>n||j>n) continue;
			if(a[l]>mx[l-1]){
				if(i>=1){
					f[i][j][1] |= (f[i-1][j][0]|f[i-1][j][1]);
				}
				if(j>=1){
					f[i][j][0] |= (f[i][j-1][0]|f[i][j-1][1]);
				}
			}else{
				if(i>=1){
					f[i][j][1] |= f[i-1][j][1];
				}
				if(j>=1){
					f[i][j][0] |= f[i][j-1][0];
				}
			}
		}
	}
	puts((f[n][n][0]|f[n][n][1])?"YES":"NO");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve(); 
}