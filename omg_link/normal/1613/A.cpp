#include <stdio.h>
#include <algorithm>

using std::min;

using ll = long long;

void solve(){
	ll x1,p1,x2,p2;
	scanf("%lld%lld%lld%lld",&x1,&p1,&x2,&p2);
	ll p = min(p1,p2);
	p1 -= p;
	p2 -= p;
	if(p1>8){
		puts(">");
		return;
	}
	if(p2>8){
		puts("<");
		return;
	}
	for(int i=0;i<p1;i++) x1 *= 10;
	for(int i=0;i<p2;i++) x2 *= 10;
	if(x1>x2){
		puts(">");
	}else if(x1==x2){
		puts("=");
	}else{
		puts("<");
	}
	return;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}