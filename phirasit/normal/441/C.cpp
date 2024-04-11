#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

int n, m, k;

void display(vector<pii> r) {
	printf("%d ", r.size());
	for(int i = 0;i < r.size();i++) {
		printf("%d %d ", r[i].second, r[i].first);
	}
	printf("\n");
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	int x = 1, y = 1, d = 1;
	int cnt = 0, i = 1;
	vector<pii> ans;
	while(1) {
		if(i < k && ans.size() >= 2) {
			display(ans);
			ans.clear();
			i++;
		}
		ans.push_back(make_pair(x, y));
		if(x + d < 1 || x + d > m) {
			y++;
			d = -d;
		}else {
			x += d;
		}
		if(y > n) {
			break;
		}
	}
	display(ans);
	return 0;
}