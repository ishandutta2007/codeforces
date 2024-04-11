#include <stdio.h>
#include <algorithm>

using std::abs;

void solve(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int n = abs(a-b);
	if(a>2*n||b>2*n||c>2*n){
		puts("-1");
	}else{
		if(c<=n)
			printf("%d\n",c+n);
		else
			printf("%d\n",c-n);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}