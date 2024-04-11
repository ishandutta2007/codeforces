#include <bits/stdc++.h>
using namespace std;

long long arr[200000];
typedef pair<long long,long long> P;
P sum[200000];

int main(void) {
	int n;
	scanf("%d\n",&n);
	for(int i=0;i<n;i++) {
		scanf("%lld ",&arr[i]);
		sum[i]=P(arr[i]-i,arr[i]);
	}
	sort(sum,sum+n);
	long long cnt=sum[0].second;
	long long ret=cnt;
	for(int i=1;i<n;i++) {
		if (sum[i-1].first!=sum[i].first) {
			cnt=0;
		}
		cnt+=sum[i].second;
		ret=max(ret,cnt);
	}
	printf("%lld",ret);
}