#include <stdio.h>
#include <vector>

using namespace std;

vector<int> ans;
int n, v;

int main() {
	scanf("%d%d", &n, &v);
	for(int i = 1;i <= n;i++) {
		int sz;
		scanf("%d", &sz);
		bool found = false;
		for(int j = 0;j < sz;j++) {
			int val;
			scanf("%d", &val);
			if(val < v) {
				found = true;
			}
		}
		if(found) {
			ans.push_back(i);
		}
	}
	printf("%d\n", ans.size());
	for(int i = 0;i < ans.size();i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}