#include<cstdio>
int n,a[100001],x,t;
int main(){
	scanf("%d",&n);
	t=n;
	while(n--){
		scanf("%d",&x);
		a[x]=1;
		while(a[t])
			printf("%d ",t--);
		puts("");
	}
	return 0;
}