#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int n;
	scanf("%d\n",&n);
	int arr[100000];
	for(int i=0;i<n;i++) {
		scanf("%d ",&arr[i]);
	}
	int cnt[31];
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<n;i++) {
		for(int j=0;j<31;j++) {
			if ((arr[i]&(1<<j))!=0) {
				cnt[j]++;
			}
		}
	}
	int ret;
	int maxi=-1;
	for(int i=0;i<n;i++) {
		for(int j=0;j<31;j++) {
			if ((arr[i]&(1<<j))!=0) {
				cnt[j]--;
			}
		}
		int val=0;
		for(int j=0;j<31;j++) {
			if (cnt[j]==0) {
				val+=(1<<j);
			}
		}
		if (val>maxi) {
			maxi=val;
			ret=i;
		}
		for(int j=0;j<31;j++) {
			if ((arr[i]&(1<<j))!=0) {
				cnt[j]++;
			}
		}
	}
	printf("%d ",arr[ret]);
	for(int i=0;i<n;i++) {
		if (i!=ret) {
			printf("%d ",arr[i]);
		}
	}
	return 0;
}