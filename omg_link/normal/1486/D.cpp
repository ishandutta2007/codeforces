#include <stdio.h>
#include <algorithm>
#define MN 200000

int n,k,a[MN+5],pre[MN+5];

bool check(int s){
	int minPre = 0x3fffffff;
	for(int i=1;i<=n;i++){
		pre[i] = pre[i-1] + (a[i]>=s?1:-1);
		if(i>=k)
			minPre = std::min(minPre,pre[i-k]);
		if(pre[i]-minPre>=1)
			return true;
	}
	return false;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int l=1,r=n,mid;
	while(l<=r){
		mid = (l+r)>>1;
		if(check(mid))
			l = mid+1;
		else
			r = mid-1;
	}
	printf("%d\n",r);
}