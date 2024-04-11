#include <bits/stdc++.h>
using namespace std;

int arr[400000];
int cnt[400000];

int main(void) {
	int n,I;
	scanf("%d %d\n",&n,&I);
	I*=8;
	I/=n;
	if (I>=20) {
		printf("0");
		return 0;
	}
	int lim=1;
	for(int i=0;i<I;i++) {
		lim*=2;
	}
	for(int i=0;i<n;i++) {
		scanf("%d ",&arr[i]);
	}
	sort(arr,arr+n);
	int ind=0;
	int prev=arr[0];
	for(int i=0;i<n;i++) {
		if (prev!=arr[i]) {
			ind++;
		}
		cnt[ind]++;
		prev=arr[i];
	}
	if (ind+1<=lim) {
		printf("0");
		return 0;
	}
	int ret=0;
	int sum=0;
	for(int i=0;i<lim;i++) {
		sum+=cnt[i];
	}
	ret=max(ret,sum);
	for(int i=lim;i<=ind;i++) {
		sum-=cnt[i-lim];
		sum+=cnt[i];
		ret=max(ret,sum);
	}
	printf("%d",n-ret);
}