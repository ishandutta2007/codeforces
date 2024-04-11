#include <stdio.h>

bool check(int a,int b,int c){
	return b+c==a||(b==c&&a%2==0);
}

void solve(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(check(a,b,c)||check(b,a,c)||check(c,a,b))
		puts("YES");
	else
		puts("NO");
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}