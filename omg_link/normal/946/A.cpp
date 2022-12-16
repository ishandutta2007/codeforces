#include <stdio.h>
inline int abs(int a){return a>0?a:-a;}
int main(){
	int n,a,b=0; scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a),b+=abs(a);
	printf("%d",b);
}