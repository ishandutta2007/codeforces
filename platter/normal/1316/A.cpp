#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long arr[3333];

int main(void) {
	int tc;
	scanf("%d\n",&tc);
	for(int t=0;t<tc;t++) {
		scanf("%lld %lld\n",&n,&m);
		long long sum=0;
		for(int i=0;i<n;i++) {
			scanf("%lld ",&arr[i]);
			sum+=arr[i];
		}
		scanf("\n");
		printf("%d\n",min(sum,m));
	}
}