#include<bits/stdc++.h>
#define LL long long
#define mo 1000000007
using namespace std;
int n,a[300010],tail;
int main() {
	scanf("%d",&n);
	printf("1");
	for (int i=1;i<=n;i++){
		int o;
		scanf("%d",&o);
		a[o]=1;
		while (a[n-tail]==1) tail++;
		printf(" %d",i-tail+1);
	}
}