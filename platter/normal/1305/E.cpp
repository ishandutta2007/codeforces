#include <bits/stdc++.h>
using namespace std;

long long maxi[5001];

void cal() {
	maxi[1]=0;
	for(int i=2;i<=5000;i++) {
		maxi[i]=maxi[i-1]+(i-1)/2;
	}
}

const long long INF=6e8;

int main(void) {
	cal();
	long long n,m;
	scanf("%lld %lld\n",&n,&m);
	if (m>maxi[n]) {
		printf("-1");
		return 0;
	}
	if (m==maxi[n]) {
		for(int i=1;i<=n;i++) {
			printf("%d ",i);
		}
		return 0;
	}
	for(int i=n-1;i>=1;i--) {
		if (m>=maxi[i]) {
			for(int j=1;j<=i;j++) {
				printf("%d ",j);
			}
			printf("%d ",i+1+2*(maxi[i+1]-m));
			for(int j=i+2;j<=n;j++) {
				printf("%lld ",30000*j+389247);
			}
			return 0;
		}
	}
}