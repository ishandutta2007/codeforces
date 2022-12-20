#include <stdio.h>
#include <algorithm>

typedef long long LL;

LL a,b,n,m;

void no(){
	puts("No");
}

void yes(){
	puts("Yes");
}

void solve(){
	scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
	if(n+m>a+b){
		no();
		return;
	}
	if(m>std::min(a,b)){
		no();
		return;
	}
	yes();
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}