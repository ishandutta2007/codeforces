#include <stdio.h>
#define MN 100000

int n,q,k,a[MN+5];
long long ans[MN+5];

int main(){
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){	
		ans[i] = ans[i-1] + (a[i+1]-1)-(a[i-1]+1)+1-1;
	}
	for(int l,r;q--;){
		scanf("%d%d",&l,&r);
		if(l==r){
			printf("%d\n",k-1);
		}else{
			printf("%lld\n",ans[r-1]-ans[l]+k-a[r-1]-1+a[l+1]-1-1);
		}
	}
}