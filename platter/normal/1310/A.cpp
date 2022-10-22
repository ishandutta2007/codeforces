#include <bits/stdc++.h>
using namespace std;

typedef pair<long long,long long> P;
P arr[200001];

int main(void) {
	int n;
	scanf("%d\n",&n);
	for(int i=0;i<n;i++) {
		int x;
		scanf("%lld ",&x);
		arr[i].first=x;
	}
	scanf("\n");
	for(int i=0;i<n;i++) {
		int x;
		scanf("%lld ",&x);
		arr[i].second=x;
	}
	scanf("\n");
	sort(arr,arr+n);
	arr[n].first=2e9;
	priority_queue<long long> pq;
	long long ret=0;
	long long sum=0;
	int ind=0;
	while (1) {
		do {
			pq.push(arr[ind].second);
			sum+=arr[ind].second;
			ind++;
		} while (ind<n&&arr[ind-1].first==arr[ind].first);
		for(int i=arr[ind-1].first;i<arr[ind].first&&(!pq.empty());i++) {
			sum-=pq.top();
			pq.pop();
			ret+=sum;
		}
		if (ind==n) {
			break;
		}
	}
	printf("%lld",ret);
}