#include <stdio.h>
typedef long long LL;

void solve(){
	LL n;
	scanf("%lld",&n);
	for(LL i=1,j=10000;i*i*i<=n;i++){
		while(j>0&&i*i*i+j*j*j>n) j--;
		if(j==0) break;
		if(i*i*i+j*j*j==n){
			puts("YES");
			return;
		}
	}
	puts("NO");
	return;
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}