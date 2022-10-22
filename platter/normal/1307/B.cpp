#include <bits/stdc++.h>
using namespace std;

long long arr[100000];

int main(void) {
	int c;
	scanf("%d\n",&c);
	for(int t=0;t<c;t++) {
		int n;
		long long x;
		scanf("%d %lld\n",&n,&x);
		long long maxi=0;
		bool flag=false;
		for(int i=0;i<n;i++) {
			scanf("%lld ",&arr[i]);
			maxi=max(maxi,arr[i]);
			if (arr[i]==x) {
				flag=true;
			}
		}
		if (flag) {
			printf("1\n");
			continue;
		}
		printf("%lld\n",max(2LL,(x-1)/maxi+1));
	}
}