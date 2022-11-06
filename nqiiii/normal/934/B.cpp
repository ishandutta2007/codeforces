#include<cstdio>
int n;
int main(){
	scanf("%d",&n);
	if(n>36) printf("-1");
	else{
		for(int i=1;i<=n/2;++i) printf("8");
		for(int i=1;i<=n%2;++i) printf("4");
	}
}