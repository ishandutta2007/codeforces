#include <bits/stdc++.h>
using namespace std;

int n,m;

long long fastpow(long long a,long long b) {
	if (b==0)
	return 1%m;
	if (b%2==1) {
		return (fastpow(a,b-1)*a)%m;
	}
	long long half=fastpow(a,b/2);
	return (half*half)%m;
}

int cnt[1000];
long long arr[200000];

int main(void) {
	scanf("%d %d\n",&n,&m);
	if (m==1) {
		printf("0");
		return 0;
	}
	for(int i=0;i<n;i++) {
		scanf("%lld ",&arr[i]);
		int x=arr[i]%m;
		if (cnt[x]!=0) {
			printf("0");
			return 0;
		}
		cnt[x]=1;
	}
	long long ret=1;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			long long val=arr[i]-arr[j];
			if (val<0) {
				val=-val;
			}
			val%=m;
			ret*=val;
			ret%=m;
		}
	}
	printf("%lld",ret);
}