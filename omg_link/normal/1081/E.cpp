#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#define MN 100000
typedef long long LL;
int n;
LL x[MN+5],a[MN+5],b[MN+5];
void solve(int t){
	for(int i=sqrt(x[t]);i>=1;i--)
		if(x[t]%i==0){
			if(((i+x[t]/i)&1)==0){
				a[t]=(i+x[t]/i)>>1;
				b[t]=x[t]/i-a[t];
				if(a[t]>b[t]) std::swap(a[t],b[t]);
				if(a[t]>b[t-2]) return;
			}
		}
	puts("No");
	exit(0);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		if(!(i&1)){
			scanf("%lld",&x[i]);
			solve(i);
		}
	}
	x[1]=a[2]*a[2];
	if(x[1]<=0) return 0*puts("No");
	for(int i=3;i<=n;i+=2){
		x[i]=a[i+1]*a[i+1]-b[i-1]*b[i-1];
		if(x[i]<=0) return 0*puts("No");
	}
	puts("Yes");
	for(int i=1;i<=n;i++)
		printf("%lld ",x[i]);
}