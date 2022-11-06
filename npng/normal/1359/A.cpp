#include <cstdio>
int n,m,k;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		int num=n/k;
		if(m<=num){
			printf("%d\n",m);
		}
		else{
			int last=m-num;
			last=(last+(k-1)-1)/(k-1);
			printf("%d\n",num-last);
		}
	}
	return 0;
}