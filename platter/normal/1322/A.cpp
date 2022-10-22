#include <bits/stdc++.h>
using namespace std;

int arr[1000005];
int cnt[1000005];

int main(void) {
	int n;
	scanf("%d\n",&n);
	int open=0;
	int close=0;
	for(int i=0;i<n;i++) {
		char x;
		scanf("%c",&x);
		if (x=='(') {
			arr[i]=1;
			open++;
		}
		else {
			arr[i]=-1;
			close++;
		}
	}
	if (open!=close) {
		printf("-1");
		return 0;
	}
	cnt[0]=0;
	for(int i=0;i<n;i++) {
		cnt[i+1]=cnt[i]+arr[i];
	}
	int ret=0;
	bool flag=(cnt[1]<0);
	int ind=1;
	while (ind<=n) {
		if (cnt[ind]<0) {
			while (ind<=n&&cnt[ind]<=0) {
				ret++;
				ind++;
			}
		}
		else {
			ind++;
		}
	}
	printf("%d",ret);
}