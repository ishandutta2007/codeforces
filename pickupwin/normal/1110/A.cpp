#include <cstdio>

int B, N;
int s=0;

void Show(int a){
	if(a==0)	puts("even");
	else	puts("odd");
}

int main(){
	
	scanf("%d%d", &B, &N);
	
	if(B&1){
		for(int i=1, a;i<=N;++i){
			scanf("%d", &a);
			s+=a;
		}
		Show(s&1);
	}
	else{
		for(int i=1, a;i<N;++i)	scanf("%d", &a);
		scanf("%d", &s);
		Show(s&1);
	}
	
	return 0;
}