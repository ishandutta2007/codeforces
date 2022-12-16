#include <stdio.h>
#include <algorithm>

bool check(int k1,int k2,int w){
	if(k1>k2) std::swap(k1,k2);
	return k1+(k2-k1)/2>=w;
}

void solve(){
	int n,k1,k2,w,h;
	scanf("%d%d%d",&n,&k1,&k2);
	scanf("%d%d",&w,&h);
	if(!check(k1,k2,w)){
		puts("NO");
		return;
	}
	if(!check(n-k1,n-k2,h)){
		puts("NO");
		return;
	}
	puts("YES");
	return;
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}