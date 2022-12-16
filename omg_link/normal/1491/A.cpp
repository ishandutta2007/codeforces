#include <stdio.h>
#define MN 100000

int n,q,a[MN+5],c[2];

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[a[i]]++;
	}
	for(int i=1;i<=q;i++){
		int t,p;
		scanf("%d%d",&t,&p);
		if(t==1){
			c[a[p]]--;
			a[p] ^= 1;
			c[a[p]]++;
		}else{
			printf("%d\n",p<=c[1]);
		}
	}
}