#include <cstdio>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int l,r;
		scanf("%d%d",&l,&r);
		if(l==1){
			printf("%d %d\n",1,2);
			continue;
		}
		if((l<<1)>r){
			puts("-1 -1");
			continue;
		}
		printf("%d %d\n",l,(l<<1));
	}
	return 0;
}