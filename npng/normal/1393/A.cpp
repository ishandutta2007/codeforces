#include <cstdio>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		printf("%d\n",(n>>1)+1);
	}
	return 0;
}