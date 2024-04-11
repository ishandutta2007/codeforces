#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int tc;
	scanf("%d\n",&tc);
	for(int t=0;t<tc;t++) {
		long long a,b;
		scanf("%lld %lld\n",&a,&b);
		if (a%b==0) {
			printf("0\n");
		}
		else {
			printf("%lld\n",b-a%b);
		}
	}
}