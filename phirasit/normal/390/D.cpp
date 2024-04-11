#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

stack<vector<pii> > stk;

int n, m, k;
int ans = 0;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int l = 1;k > 0;l++) {
		for(int i = 1;i <= n && k > 0;i++) {
			int j = l-i+1;
			if(j <= 0 || j > m) continue;
			vector<pii> path;
			for(int ii = 1;ii <= i;ii++) {
				path.push_back(make_pair(ii, 1));
			}
			for(int jj = 2;jj <= j;jj++) {
				path.push_back(make_pair(i, jj));
			}
			ans += path.size();
			stk.push(path);
			k--;
		}
	}
	printf("%d\n", ans);
	while(!stk.empty()) {
		vector<pii> tmp = stk.top();
		stk.pop();
		for(int i = 0;i < tmp.size();i++) {
			printf("(%d,%d) ", tmp[i].first, tmp[i].second);
		}
		printf("\n");
	}
	return 0;
}