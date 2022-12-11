#include <stdio.h>
#include <vector>
#include <set>
#include <map>

#define N 200010
#define A first
#define B second

using namespace std;

typedef pair<int, int> PII;

map<int, int> next, back;
set<int> use;

PII arr[N];
int ans[N];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) {
		scanf("%d%d", &arr[i].A, &arr[i].B);
		next[arr[i].A] = arr[i].B;
		back[arr[i].B] = arr[i].A;
	}
	int idx = 0, k = 0;
	while(idx <= n) {
		use.insert(k);
		ans[idx] = k;
		k = next[k];
		idx += 2;
	}
	for(map<int, int>::iterator it = next.begin(); it != next.end();it++) {
		if(back[it->A] == 0 && !use.count(it->A)) {
			k = it->A;
		}
	}
	idx = 1;
	while(idx <= n) {
		use.insert(k);
		ans[idx] = k;
		k = next[k];
		idx += 2;
	}
	for(int i = 1;i <= n;i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}