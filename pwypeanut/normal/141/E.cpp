#include <bits/stdc++.h>
using namespace std;

int N, E, p[1005], zeroes, ones;
vector< pair< int, pair<int, int> > > V, tree, tree2;
bool intree[300005];
map<pair< int, pair<int, int> >, int> M;

int fp(int x) {
	if (x == p[x]) return x;
	else return p[x] = fp(p[x]);
}

void merge(int x, int y) {
	x = fp(x);
	y = fp(y);
	p[x] = y;
}

void construct_tree() {
	for (int i = 0; i < N; i++) p[i] = i;
	for (int i = 0; i < tree.size(); i++) {
		if (tree[i].first == 1) merge(tree[i].second.first, tree[i].second.second);
	}
	//for (int i = 0; i < tree.size(); i++) printf("%d ", M[tree[i]]);
	//printf("\n");
	if (zeroes == ones) {
		printf("%d\n", zeroes+ones);
		for (int i = 0; i < tree.size(); i++) printf("%d ", M[tree[i]]);
		printf("\n");
		exit(0);
	}
}

int main() {
	scanf("%d%d", &N, &E);
	for (int i = 0; i < E; i++) {
		int a, b;
		char c;
		scanf("%d %d %c", &a, &b, &c);a--;b--;
		V.push_back(make_pair(c == 'S', make_pair(a, b)));
		M[make_pair(c == 'S', make_pair(a, b))] = i+1;
	}
	sort(V.begin(), V.end());
	for (int i = 0; i < N; i++) p[i] = i;
	for (int i = 0; i < E; i++) {
		int a = fp(V[i].second.first), b = fp(V[i].second.second);
		if (a == b) continue;
		merge(a, b);
		tree.push_back(V[i]);
		if (V[i].first == 1) ones++;
		else zeroes++;
		intree[i] = 1;
	}
	if (tree.size() != N - 1) {
		printf("-1\n");
		return 0;
	}
	construct_tree();
	for (int i = 0; i < E; i++) {
		if (V[i].first == 0) continue;
		if (intree[i]) continue;
		if (fp(V[i].second.first) == fp(V[i].second.second)) continue;
		for (int j = 0; j < N; j++) p[j] = j;
		merge(V[i].second.first, V[i].second.second);
		int rem;
		for (int j = tree.size() - 1; j >= 0; j--) {
			int a = tree[j].second.first, b = tree[j].second.second;
			if (fp(a) == fp(b)) {
				rem = j;
				break;
			} else merge(a, b);
		}
		for (int j = 0; j < tree.size(); j++) if (j != rem) tree2.push_back(tree[j]);
		tree2.push_back(V[i]);
		sort(tree2.begin(), tree2.end());
		tree = tree2;
		tree2.clear();
		zeroes--;
		ones++;
		construct_tree();
		
	}
	printf("-1\n");
}