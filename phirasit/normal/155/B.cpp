#include <stdio.h>
#include <algorithm>

#define N 1010

using namespace std;

typedef pair<int, int> pii;

pii arr[N];
int n;

int cmp(pii a, pii b) {
	if(a.second != b.second) {
		return a.second > b.second;
	}
	return a.first > b.first;
}
int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d%d", &arr[i].first, &arr[i].second);
	}
	sort(arr, arr+n, cmp);
	int ans = 0, cnt = 1;
	for(int i = 0;i < n && cnt;i++) {
		ans += arr[i].first;
		cnt += arr[i].second - 1;
	}
	printf("%d\n", ans);
	return 0;
}