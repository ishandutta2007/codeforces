#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

int n;
long long arr[500000];
long long left[500000];
long long right[500000];
long long ans[500000];
typedef pair<long long,int> P;

int main(void) {
	scanf("%d\n",&n);
	for(int i=0;i<n;i++) {
		scanf("%lld ",&arr[i]);
	}
	stack<P> s;
	long long sum=0;
	for(int i=0;i<n;i++) {
		if (s.empty()||s.top().first<arr[i]) {
			s.push(P(arr[i],1));
			sum+=arr[i];
		}
		else {
			int cnt=1;
			while (!s.empty()&&s.top().first>=arr[i]) {
				sum-=s.top().first*s.top().second;
				cnt+=s.top().second;
				s.pop();
			}
			s.push(P(arr[i],cnt));
			sum+=cnt*arr[i];
		}
		left[i]=sum;
	}
	sum=0;
	while (!s.empty()) {
		s.pop();
	}
	for(int i=n-1;i>=0;i--) {
		if (s.empty()||s.top().first<arr[i]) {
			s.push(P(arr[i],1));
			sum+=arr[i];
		}
		else {
			int cnt=1;
			while (!s.empty()&&s.top().first>=arr[i]) {
				sum-=s.top().first*s.top().second;
				cnt+=s.top().second;
				s.pop();
			}
			s.push(P(arr[i],cnt));
			sum+=cnt*arr[i];
		}
		right[i]=sum;
	}
	int proper;
	long long ret=0;
	for(int i=0;i<n;i++) {
		long long temp=left[i]+right[i]-arr[i];
		if (temp>ret) {
			ret=temp;
			proper=i;
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