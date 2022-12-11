#include <stdio.h>
#include <algorithm>
#include <vector>

#define N 100010

using namespace std;

vector< pair<int, int> > ans;

int idx[N];
int dis[N];
int deg[N];
int n, k;

int cmpDIS(int a, int b) {
	return dis[a] < dis[b];
}
int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) {
		scanf("%d", &dis[i]);
		idx[i] = i;
		deg[i] = 0;
	}
	sort(idx+1, idx+n+1, cmpDIS);
	for(int i = 1, j = 2;j <= n;j++) {
		while(i < j && (dis[idx[i]]+1 < dis[idx[j]] || deg[idx[i]] >= k)) {
			i++;
		}
		if(i >= j || dis[idx[j]] != dis[idx[i]]+1) {
			printf("-1\n");
			return 0;
		}
		ans.push_back(make_pair(idx[i], idx[j]));
		deg[idx[i]]++;
		deg[idx[j]]++;
		if(deg[idx[i]] >= k) {
			i++;
		}
	}
	if(dis[idx[1]] > 0) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", ans.size());
	for(int i = 0;i < ans.size();i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}