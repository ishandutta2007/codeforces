#include <stdio.h>
#include <algorithm>
#define MN 200000
int n;
struct xxx{
	int a,b,i;
}x[MN+5];
bool cmp1(xxx a,xxx b){
	return a.a>b.a;
}
bool cmp2(xxx a,xxx b){
	return a.i<b.i;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i].a);
		x[i].a=n-x[i].a;
		x[i].i=i;
	}
	std::sort(x+1,x+1+n,cmp1);
	int cc=0;
	for(int i=1;i<=n;i++){
		++cc;
		if(i+x[i].a-1>n) return 0*puts("Impossible");
		for(int j=i;j<=i+x[i].a-1;j++){
			if(x[j].a!=x[i].a) return 0*puts("Impossible");
			x[j].b=cc;
		}
		i=i+x[i].a-1;
	}
	std::sort(x+1,x+1+n,cmp2);
	puts("Possible");
	for(int i=1;i<=n;i++)
		printf("%d ",x[i].b);
}