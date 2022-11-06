#include <cstdio>
void solve(){
	int x,y;
	scanf("%d%d",&x,&y);
	if(x>y){
		printf("%d\n",x+y);
		return;
	}
	int tmp=y/x-1;
	x+=tmp*x;
	printf("%d\n",(x+y)/2);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}