#include <bits/stdc++.h>
using namespace std;

typedef pair<long long,long long> P;
int n;
P arr[200000];
P temp[200000];

long long ans(int l,int r) {
	if (l==r) {
		return 0;
	}
	int mid=(l+r)/2;
	long long ret=ans(l,mid)+ans(mid+1,r);
	for(int i=l;i<=r;i++) {
		temp[i]=arr[i];
	}
	long long sum=0;
	int cnt=0;
	int lind=l;
	int rind=mid+1;
	long long midv=-2e9;
	for(int i=l;i<=mid;i++) {
		midv=max(midv,temp[i].first);
	}
    for(int i=l;i<=r;i++) {
		if (rind==r+1||(lind!=mid+1&&(temp[lind].second<=temp[rind].second))) {
			sum+=midv-temp[lind].first;
			cnt++;
			arr[i]=temp[lind];
			lind++;
		}
		else {
			ret+=(temp[rind].first-midv)*cnt+sum;
			arr[i]=temp[rind];
			rind++;
		}
	}
	return ret;
}

int main(void) {
	scanf("%d\n",&n);
	for(int i=0;i<n;i++) {
		long long x;
		scanf("%lld ",&x);
		arr[i].first=x;
	}
	scanf("\n");
	for(int i=0;i<n;i++) {
		long long v;
		scanf("%lld ",&v);
		arr[i].second=v;
	}
	sort(arr,arr+n);
	printf("%lld",ans(0,n-1));
}