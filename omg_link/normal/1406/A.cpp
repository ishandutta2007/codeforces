#include <stdio.h>
#define MN 100

int n,a[MN+5],c[MN+5]; 

void solve(){
	scanf("%d",&n);
	for(int i=0;i<=100;i++)
		c[i] = 0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[a[i]]++;
	}
	int ans = 0;
	for(int i=0;i<=100;i++){
		if(c[i]<2){
			ans += i;
			break;
		}
	}
	for(int i=0;i<=100;i++){
		if(c[i]==0){
			ans += i;
			break;
		}
	}
	printf("%d\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}