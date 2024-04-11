#include<cmath>
#include<cstdio>
int t;
int main(){
	scanf("%d",&t);
	for(;t--;){
		int x; scanf("%d",&x);
		if(!x){
			printf("1 1\n"); continue;
		}
		bool suc=0;
		for(int i=1;i*i<x;++i) if(x%i==0){
			int t=x/i;
			if((t+i)%2) continue;
			int n=(t+i)/2,m=(t-i)/2;
			if(n/(n/m)==m){
				suc=1; printf("%d %d\n",n,n/m); break;
			}
		}
		if(!suc) printf("-1\n");
	}
}