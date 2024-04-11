#include <cstdio>
#include <vector>

const int N = 200000;

std::vector <int> ans[N];
std::vector < std::pair<int, int> > edge[N];

int max;
void dfs (int u, int par, int day) {

	int cnt = 0;
	for (int i=0; i<edge[u].size(); i++) {
		std::pair<int, int> v = edge[u][i];		
		
		if (v.first == par) continue;		
		if (day == cnt) cnt++;
		
		ans[cnt].push_back (v.second);
		dfs(v.first, u, cnt++);
	}
	
	max = (max < cnt ? cnt : max);
}

int main () {
	int n;
	scanf ("%d", &n);
	
	int u, v;
	for (int i=1; i<n; i++) {
		scanf ("%d %d", &u, &v);
		u--, v--;
		
		edge[u].push_back (std::make_pair(v, i));
		edge[v].push_back (std::make_pair(u, i));
	}
	
	dfs (0, 0, -1);
	
	printf ("%d\n", max);
	for (int i=0; i<max; i++) {
		printf ("%d", ans[i].size());
		for (int j=0; j<ans[i].size(); j++) {
			printf (" %d", ans[i][j]);
		}
		printf ("\n");
	}	
	
	return 0;
}