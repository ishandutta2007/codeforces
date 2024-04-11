#include <stdio.h>
#include <queue>
#include <algorithm>

#define N 500010

using namespace std;

priority_queue<long long> heap;

long long s[N], m[N], ans[N];
int idx[N];
int n, k;

int cmp(int a, int b) {
	return s[a] < s[b];
}
int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0;i < n;i++) {
		scanf("%I64d%I64d", &s[i], &m[i]);
		idx[i] = i;
	}
	sort(idx, idx+n, cmp);
	for(int i = 0;i < n;i++) {
		int v = idx[i];
		if(k > 0) {
			heap.push(-(ans[v] = s[v] + m[v])); 
			k--;
		}else {
			long long top = heap.top();
			heap.pop();
			ans[v] = max(-top, s[v]) + m[v];
			heap.push(-ans[v]);
		}
	}
	for(int i = 0;i < n;i++) {
		printf("%I64d\n", ans[i]);
	}
	return 0;
}