#include <cstdio>
using namespace std;

int arr[4001];

int main() {
	int t;
	scanf("%d\n",&t);
	for(int tc=0;tc<t;tc++) {
		for(int i=0;i<=4000;i++) {
			arr[i]=0;
		}
		int n,s,k;
		scanf("%d %d %d\n",&n,&s,&k);
		for(int i=0;i<k;i++) {
			int x;
			scanf("%d ",&x);
			if (x-s>=-2000&&x-s<=2000) {
				arr[x-s+2000]=1;
			}
		}
		for(int i=0;i<=2000;i++) {
			if ((s-i>0&&arr[2000-i]==0)||(s+i<=n&&arr[2000+i]==0)) {
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}