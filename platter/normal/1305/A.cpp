#include <bits/stdc++.h>
using namespace std;

int a[123];
int b[123];

int main(void) {
	int tc;
	scanf("%d\n",&tc);
	for(int t=0;t<tc;t++) {
		int n;
		scanf("%d\n",&n);
		for(int i=0;i<n;i++) {
			scanf("%d ",&a[i]);
		}
		scanf("\n");
		for(int i=0;i<n;i++) {
			scanf("%d ",&b[i]);
		}
		scanf("\n");
		sort(a,a+n);
		sort(b,b+n);
		for(int i=0;i<n;i++) {
			printf("%d ",a[i]);
		}
		printf("\n");
		for(int i=0;i<n;i++) {
			printf("%d ",b[i]);
		}
		printf("\n");
	}
}