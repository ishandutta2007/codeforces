#include <cstdio>

int n;
long long arr[100000];
long long ans[100000];

int main(void) {
	scanf("%d\n",&n);
	for(int i=0;i<n;i++) {
		scanf("%lld ",&arr[i]);
	}
	long long ret=0;
	int proper;
	for(int cut=0;cut<n;cut++) {
		long long cnt=0;
		long long now=arr[cut];
		for(int i=cut;i>=0;i--) {
			if (arr[i]<now) {
				now=arr[i];
			}
			cnt+=now;
		}
		now=arr[cut];
		for(int i=cut+1;i<n;i++) {
			if (arr[i]<now) {
				now=arr[i];
			}
			cnt+=now;
		}
		if (cnt>ret) {
			proper=cut;
			ret=cnt;
		}
	}
	long long now=arr[proper];
	for(int i=proper;i>=0;i--) {
		if (arr[i]<now) {
			now=arr[i];
		}
		ans[i]=now;
	}
	now=arr[proper];
	for(int i=proper+1;i<n;i++) {
		if (arr[i]<now) {
			now=arr[i];
		}
		ans[i]=now;
	}
	for(int i=0;i<n;i++) {
		printf("%lld ",ans[i]);
	}
}