#include <stdio.h>
#include <algorithm>

int check(int a,int b){
	if(b==1) return 0x3fffffff;
	int r = 0;
	while(a!=0){
		a = a/b;
		r++;
	}
	return r;
}

void solve(){
	int a,b,ans=0x3fffffff;
	scanf("%d%d",&a,&b);
	for(int i=0;i<40;i++){
		ans = std::min(ans,check(a,b+i)+i);
	}
	printf("%d\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}