#include <cstdio>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		if(n%4==0){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}