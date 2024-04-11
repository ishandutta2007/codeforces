#include <stdio.h>
#define MN 200000
typedef long long LL;
int n,q;
LL a[MN+5],b;
int bin(LL key){
	int l=1,r=n,mid;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid]>=key)r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]+=a[i-1];
	}
	while(q--){
		scanf("%lld",&b);
		int p=bin(b);
		printf("%d %lld\n",p,b-a[p-1]);
	}
}