#include <cstdio>
int main(){
	int T;
	int n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		printf("%d\n",((n*m+1)>>1));
	}
	return 0;
}