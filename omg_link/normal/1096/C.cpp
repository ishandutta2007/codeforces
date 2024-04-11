#include <stdio.h>
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
void solve(){
	int a,b=180;
	scanf("%d",&a);
	int c=gcd(a,b);
	a/=c,b/=c;
	if(b-a==1) b<<=1;
	printf("%d\n",b);
}
int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}