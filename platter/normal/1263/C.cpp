#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int c;
	scanf("%d\n", &c);
	for(int t=0;t<c;t++) {
		int n;
		scanf("%d\n", &n);
		int ret[1000000];
		ret[0]=0;
		int val=n;
		int ind=1;
		while (val>0) {
			if (ret[ind-1]!=n/val) {
				ret[ind]=n/val;
				ind+=1;
			}
			val=min(n/(ret[ind-1]+1),val-1);
		}
		printf("%d\n",ind);
		for(int i=0;i<ind;i++) {
			printf("%d ", ret[i]);
		}
		printf("\n");
	}
	return 0;
}