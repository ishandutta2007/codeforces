#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int c;
	scanf("%d\n", &c);
	for(int t=0;t<c;t++) {
		int arr[2000];
		int n,m;
		scanf("%d %d\n", &n, &m);
		for(int i=0;i<n;i++) {
			scanf("%d ", &arr[i]);
		}
		if (m<n) {
			printf("-1\n");
			continue;
		}
		if (n==2) {
		    printf("-1\n");
		    continue;
		}
		int mini1=-1;
		int mini2=-1;
		int mini=10000000;
		int total=0;
		for(int i=0;i<n;i++) {
			if (mini>arr[i]) {
				mini1=i;
				mini=arr[i];
			}
			total+=arr[i];
		}
		mini=1000000;
		for(int i=0;i<n;i++) {
			if (mini>arr[i]&&i!=mini1) {
				mini2=i;
				mini=arr[i];
			}
		}
		printf("%d\n",total*2+(m-n)*(arr[mini1]+arr[mini2]));
		for(int i=1;i<n;i++) {
			printf("%d %d\n",i,i+1);
		}
		printf("%d 1\n",n);
		for(int i=n+1;i<=m;i++) {
			printf("%d %d\n",mini1+1,mini2+1);
		}
	}
	return 0;
}