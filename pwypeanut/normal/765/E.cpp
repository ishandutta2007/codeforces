#include <bits/stdc++.h>
using namespace std;

int N, ans = 1000000000, root;
pair<int, int> pc[200005];
vector<int> adjlist[200005];

pair<int, int> dfs(int x, int p) {
	int cnt = 0;
	if (adjlist[x].size() == 1) return pc[x] = make_pair(0, -1);
	set<int> s;
	bool fail = 0;
	for (int i = 0; i < adjlist[x].size(); i++) {
		if (adjlist[x][i] == p) continue;
		pair<int, int> P = dfs(adjlist[x][i], x);
		if (P == make_pair(-1, -1)) fail = 1;
		s.insert(P.first + 1);
		if (P.second != -1) s.insert(P.second + 1);
		if (s.size() > 2) fail = 1;
	}
	if (fail) return pc[x] = make_pair(-1, -1);
	if (s.size() == 1) return pc[x] = make_pair(*s.begin(), -1);
	else return pc[x] = make_pair(*s.begin(), *s.rbegin());
}

int proc(int x) {
	while (x % 2 == 0) x/=2;
	return x;
}

void dfs2(int x, int p, pair<int, int> bag) {
	if (bag.first != -1 && bag.second != -1) return;
	//printf("%d bag: %d %d\n", x, bag.first, bag.second);
	// check if this node is viable
	if (pc[x] != make_pair(-1, -1)) {
		set<int> potate;
		potate.insert(pc[x].first);bool fail = 0;
		if (pc[x].second != -1) {
			potate.insert(pc[x].second);
		}
		for (int i = 0; i < adjlist[x].size(); i++) {
			if (adjlist[x][i] == p) continue;
			if (pc[adjlist[x][i]] == make_pair(-1, -1) || (pc[adjlist[x][i]].first != -1 && pc[adjlist[x][i]].second != -1)) fail = 1;
		}
		
		if (x != root) {
			potate.insert(bag.first);
			if (bag.second != -1) {
				potate.insert(bag.second);
				fail = 1;
			}
		}
		if (potate.size() == 1 && !fail) {
			ans = min(ans, proc(*potate.begin()));
			//printf("from %d: %d\n", x, proc(*potate.begin()));
		}
		else if (potate.size() == 2 && !fail) {
			ans = min(ans, proc(*potate.begin() + *potate.rbegin()));
			//printf("from %d: %d\n", x, proc(*potate.begin() + *potate.rbegin()));
		}
	}
	
	set<int> s;
	map<int, int> m;
	if (x != root) {
		m[bag.first]++;
		s.insert(bag.first);
		if (bag.second != -1) {
			m[bag.second]++;
			s.insert(bag.second);
		}
	}
	int picky = -1;
	for (int i = 0; i < adjlist[x].size(); i++) {
		if (adjlist[x][i] == p) continue;
		pair<int, int> P = pc[adjlist[x][i]];
		if (P == make_pair(-1, -1) || (pc[adjlist[x][i]].first != -1 && pc[adjlist[x][i]].second != -1)) {
			if (picky != -1) return;
			else {
				picky = i;
				continue;
			}
		}
		m[P.first + 1]++;
		s.insert(P.first + 1);
		if (P.second != -1) {
			m[P.second + 1]++;
			s.insert(P.second + 1);
		}
	}
	if (picky != -1) {
		if (s.size() > 2) return;
		if (s.size() == 1) dfs2(adjlist[x][picky], x, make_pair(*s.begin() + 1, -1));
		else dfs2(adjlist[x][picky], x, make_pair(*s.begin() + 1, *s.rbegin()));
	} else {
		for (int i = 0; i < adjlist[x].size(); i++) {
			if (adjlist[x][i] == p) continue;
			pair<int, int> P = pc[adjlist[x][i]];
			m[P.first + 1]--;
			if (m[P.first + 1] == 0) s.erase(s.find(P.first + 1));
			if (P.second != -1) {
				m[P.second + 1]--;
				if (m[P.second + 1] == 0) s.erase(s.find(P.second + 1));
			}
			if (s.size() == 1) dfs2(adjlist[x][i], x, make_pair(*s.begin() + 1, -1));
			else dfs2(adjlist[x][i], x, make_pair(*s.begin() + 1, *s.rbegin() + 1));
			m[P.first + 1]++;
			s.insert(P.first + 1);
			if (P.second != -1) {
				m[P.second + 1]++;
				s.insert(P.second + 1);
			}
		}
	}
	
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N-1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;b--;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	if (N == 2) {
		printf("1\n");
		return 0;
	}
	for (int i = 0; i < N; i++) if (adjlist[i].size() > 1) root = i;
	//printf("root: %d\n", root);
	dfs(root, -1);
	//printf("done\n");
	//for (int i = 0; i < N; i++) printf("%d: %d, %d\n", i, pc[i].first, pc[i].second);
	dfs2(root, -1, make_pair(-1, -1));
	if (ans != 1000000000) printf("%d\n", ans);
	else printf("-1\n");
}