#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int tc;
	scanf("%d\n",&tc);
	for(int t=0;t<tc;t++) {
		int n;
		long long k;
		scanf("%d %lld\n",&n,&k);
		long long cnt=0;
		int i;
		for(i=1;cnt<k;i++) {
			cnt+=i;
		}
		int pos=n-i;
		long long pos2=cnt-k+1+pos;
		for(i=0;i<n;i++) {
			printf("%c",(i!=pos&&i!=pos2)?'a':'b');
		}
		printf("\n");
	}
}