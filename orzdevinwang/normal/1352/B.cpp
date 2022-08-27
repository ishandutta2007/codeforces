#include<bits/stdc++.h>
using namespace std;
int T,n,k,sp,ans,d[10001];
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&k);
		if(n<k) {
			printf("NO\n");
			continue;
		}
		if(n%2) {
			if(k%2) {
				printf("YES\n");
				for(int i = 1; i < k; i++) printf("1 ");
				printf("%d\n",n-k+1);
			} else printf("NO\n");
		} else {
			if(k%2) {
				if(n/2<k) printf("NO\n");
				else {
					printf("YES\n");
					for(int i = 1; i < k; i++) printf("2 ");
					printf("%d\n",n-2*k+2);
				}
			} else {
				printf("YES\n");
				for(int i = 1; i < k; i++) printf("1 ");
				printf("%d\n",n-k+1);
			}
		}
	}
	return 0;
}