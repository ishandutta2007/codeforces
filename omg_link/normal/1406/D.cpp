#include <stdio.h>
#define MN 100000
typedef long long LL;

int n,q,a[MN+5];
LL b[MN+5],s=0;

LL ans(){
	return (s+1)>>1;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		b[i] = a[i] - a[i-1];
		if(i==1||b[i]>0) s += b[i];
	}
	printf("%lld\n",ans());
	scanf("%d",&q);
	for(int l,r,x;q--;){
		scanf("%d%d%d",&l,&r,&x);
		if(l==1||b[l]>0) s -= b[l];
		if(r<n&&b[r+1]>0) s-= b[r+1];
		b[l] += x;
		b[r+1] -= x;
		if(l==1||b[l]>0) s += b[l];
		if(r<n&&b[r+1]>0) s += b[r+1];
		printf("%lld\n",ans());
	}
}