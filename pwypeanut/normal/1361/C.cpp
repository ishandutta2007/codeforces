#include <bits/stdc++.h>
using namespace std;

int N, L[500005], R[500005], par[1600005], sze[1600006], adjcount[1600005];
vector<int> ans;
const int OFFSET = 1000001;
bool used[1000005], touched[1600005];
vector< pair<int, int> > adjlist[1000005];
int mask;

void dfs(int x, int e) {
	if (x >= OFFSET) {
		if (e % 2 == 0 && !used[((e-1)^1)+1]) {
			used[((e-1)^1)+1]=1;
			dfs(L[(e-1)/2] & mask, ((e-1)^1)+1);
			ans.push_back(((e-1)^1)+1);
		}
		if (e % 2 == 1 && !used[((e-1)^1)+1]) {
			used[((e-1)^1)+1]=1;
			dfs(R[(e-1)/2] & mask, ((e-1)^1)+1);
			ans.push_back(((e-1)^1)+1);
		}
	} else {
		while (adjlist[x].size() > 0) {
			pair<int, int> p = adjlist[x].back();
			adjlist[x].pop_back();
			if (!used[p.second]) {
				used[p.second] = 1;
				dfs(p.first, p.second);
				ans.push_back(p.second);
			}
			
		}
	}
}

int fp(int x) {
	if (par[x] == x) return x;
	else return par[x] = fp(par[x]);
}

void merge(int x, int y) {
	x = fp(x);
	y = fp(y);
	if (x != y) {
		par[x] = y;
		sze[y] += sze[x];
	}
}

bool attempt(int x, int impt) {
	ans.clear();
	for (int i = 0; i < 1000000; i++) {
		adjcount[i] = 0;
	}
	int cnt = 0;
	mask = ((1 << x) - 1);
	for (int i = 0; i < N; i++) {
		if (impt) {
			adjlist[L[i] & mask].push_back(make_pair(OFFSET + i, i * 2 + 1));
			adjlist[R[i] & mask].push_back(make_pair(OFFSET + i, i * 2 + 2));
		}
		adjcount[L[i] & mask]++;
		adjcount[R[i] & mask]++;
	}
	for (int i = 0; i <= 1000000; i++) if (adjcount[i] % 2 == 1) return false;
	if (impt) {
		memset(used, 0, sizeof(used));
		dfs(OFFSET, 1);
		if (ans.size() == 2 * N) return 1;
		else return 0;
	} else {
		for (int i = 0; i < 1600000; i++) {
			par[i] = i;
			sze[i] = 1;
		}
		memset(touched, 0, sizeof(touched));
		for (int i = 0; i < N; i++) {
			merge(L[i] & mask, OFFSET + i);
			merge(R[i] & mask, OFFSET + i);
			cnt += (touched[L[i] & mask] ^ 1);
			touched[L[i] & mask] = 1;
			cnt += (touched[R[i] & mask] ^ 1);
			touched[R[i] & mask] = 1;
			cnt += (touched[OFFSET + i] ^ 1);
			touched[OFFSET + i] = 1;
		}
		if (sze[fp(OFFSET)] == cnt) return 1;
		else return 0;
	}
	
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &L[i], &R[i]);
	}
	
	int bot = -1, top = 21, mid;
	while (bot + 1 < top) {
		mid = (bot + top) / 2;
		if (attempt(mid, 0)) {
			bot = mid;
		} else top = mid;
	} 
	attempt(bot, 1);
	printf("%d\n", bot);
	int offset = 0;
	if (((ans[0] - 1) ^ 1) != ans[1] - 1) offset++;
	
	for (int i = 0; i < ans.size(); i++) {
		if (i) printf(" ");
		printf("%d", ans[(i + offset) % ans.size()]);
	}
	printf("\n");
}