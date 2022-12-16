#include <stdio.h>
#include <algorithm>
#define INF 0x7FFFFFFF
int n,w,a,t=0,ma=0,mi=0;
int main(){
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		t+=a;
		ma=std::max(ma,t);
		mi=std::min(mi,t);
	}
	printf("%d",(w-ma)-(-mi)+1<0?0:(w-ma)-(-mi)+1);
}