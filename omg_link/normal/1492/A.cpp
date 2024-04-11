#include <stdio.h>
#include <algorithm>

void solve(){
	long long p,a,b,c;
	scanf("%lld%lld%lld%lld",&p,&a,&b,&c);
	if(p%a==0||p%b==0||p%c==0){
		puts("0");
	}else{
		printf("%lld\n",std::min({a-p%a,b-p%b,c-p%c}));
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}