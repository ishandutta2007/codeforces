#include <stdio.h>
#define MN 1000

int n;
int a[MN+5][MN+5],b[MN+5][MN+5];

void row(int x){
	for(int i=1;i<=n;i++)
		a[x][i] ^= 1;
}

void col(int x){
	for(int i=1;i<=n;i++)
		a[i][x] ^= 1;
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%1d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1,b;j<=n;j++){
			scanf("%1d",&b);
			a[i][j] ^= b;
		}
	for(int i=1;i<=n;i++)
		if(a[1][i]) col(i);
	for(int i=2;i<=n;i++)
		if(a[i][1]) row(i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]){
				puts("NO");
				return;
			}
	puts("YES");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}