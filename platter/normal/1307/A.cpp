#include <cstdio>

int main(void) {
	int c;
	scanf("%d\n",&c);
	for(int t=0;t<c;t++) {
		int n,d;
		scanf("%d %d\n",&n,&d);
		int arr[100];
		for(int i=0;i<n;i++) {
			scanf("%d ",&arr[i]);
		}
		int gone=0;
		int ret=0;
		for(int i=1;i<n;i++) {
			if (gone+i*arr[i]<=d) {
				ret+=arr[i];
				gone+=i*arr[i];
			}
			else {
				ret+=(d-gone)/i;
				break;
			}
		}
		printf("%d\n",ret+arr[0]);
	}
}