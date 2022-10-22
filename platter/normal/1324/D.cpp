#include <bits/stdc++.h>
using namespace std;

long long a[200000];
long long b[200000];
long long arr[200001];

int main(void) {
	int n;
	scanf("%d\n",&n);
	for(int i=0;i<n;i++) {
		scanf("%lld ",&a[i]);
	}
	scanf("\n");
	for(int i=0;i<n;i++) {
		scanf("%lld ",&b[i]);
	}
	for(int i=0;i<n;i++) {
		arr[i]=a[i]-b[i];
	}
	sort(arr,arr+n);
	long long ret=0;
	for(int i=0;i<n;i++) {
		ret+=arr+n-upper_bound(arr+i+1,arr+n,-arr[i]);
	}
	printf("%lld",ret);
}