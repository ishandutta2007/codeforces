#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

#define N ((1 << 16) + 10)
#define A first
#define B second

using namespace std;

typedef pair<int, int> PII;

PII arr[N];
int idx[N], pos[N];
int n;

vector<PII> ans;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d%d", &arr[i].A, &arr[i].B);
	}
	priority_queue<PII> heap;
	for(int i = 0;i < n;i++) {
		heap.push(PII(-arr[i].A, i));
	}
	while(!heap.empty()) {
		PII top = heap.top();
		heap.pop();
		int deg = -top.A, u = top.B;
		if(deg != 1 || deg != arr[u].A) {
			continue;
		}
		int v = arr[u].B;
		arr[v].B ^= u;
		arr[v].A--;
		ans.push_back(PII(u, v));
		heap.push(PII(-arr[v].A, v));
	}
	printf("%d\n", ans.size());
	for(int i = 0;i < ans.size();i++) {
		printf("%d %d\n", ans[i].A, ans[i].B);
	}
	return 0;
}