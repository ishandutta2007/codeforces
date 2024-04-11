#include <stdio.h>
#include <algorithm>
#define MN 1000

int n,a[MN+5];

void solve(){
	scanf("%d",&n);
	int x = -1, y = -1, z = -1;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(y==-1 && (x==-1 || a[i]<a[x])){
			x = i;
		}
		if(a[i]>a[x] && (y==-1 || a[i]>a[y])){
			y = i;
		}
		if(y!=-1 && a[i]<a[y]){
			puts("YES");
			printf("%d %d %d\n",x,y,i);
			return;
		}
	}
	puts("NO");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}