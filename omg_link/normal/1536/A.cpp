#include <stdio.h>
#define MN 100

int n,a[MN+5];

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(a[i]<0){
			puts("NO");
			return;
		}
	}
	puts("YES");
	puts("101");
	for(int i=0;i<=100;i++)
		printf("%d%c",i," \n"[i==100]);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}