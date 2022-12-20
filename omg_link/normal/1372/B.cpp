#include <stdio.h>
int n;
void solve(){
	scanf("%d",&n);
	for(int i=2;i*i<=n;i++){
		if(n%i == 0){
			int base = n / i;
			printf("%d %d\n",base,(i-1)*base);
			return;
		}
	}
	printf("%d %d\n",1,n-1);
}
int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}