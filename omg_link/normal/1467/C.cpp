#include <stdio.h>
#include <algorithm>
#define MN 300000
typedef long long LL;
const int INF = 0x7fffffff;

int n1,n2,n3,a1[MN+5],a2[MN+5],a3[MN+5];
int min1=INF,min2=INF,min3=INF;
LL sum1,sum2,sum3;

int main(){
	scanf("%d%d%d",&n1,&n2,&n3);
	for(int i=1;i<=n1;i++){
		scanf("%d",&a1[i]);
		min1 = std::min(min1,a1[i]);
		sum1 += a1[i];
	}
	for(int i=1;i<=n2;i++){
		scanf("%d",&a2[i]);
		min2 = std::min(min2,a2[i]);
		sum2 += a2[i];
	}
	for(int i=1;i<=n3;i++){
		scanf("%d",&a3[i]);
		min3 = std::min(min3,a3[i]);
		sum3 += a3[i];
	}
	printf("%lld\n",std::max({
		-sum1+sum2+sum3,
		sum1-sum2+sum3,
		sum1+sum2-sum3,
		sum1+sum2+sum3-2*min1-2*min2,
		sum1+sum2+sum3-2*min2-2*min3,
		sum1+sum2+sum3-2*min1-2*min3
	}));
}