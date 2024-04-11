#include <bits/stdc++.h>
using namespace std;

int N, M, Q, a[1005][1005], root;
vector< pair<int, pair<int, int> > > nodes; // value, down pointer, right pointer

int advance_right(int pos, int val) {
	for (int i = 0; i < val; i++) pos = nodes[pos].second.second;
	return pos;
}

int advance_down(int pos, int val) {
	for (int i = 0; i < val; i++) pos = nodes[pos].second.first;
	return pos;
}

int main() {
	scanf("%d%d%d", &N, &M, &Q);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &a[i][j]);
	N += 2;
	M += 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int dptr = -1, rptr = -1;
			int curno = i * M + j;
			if (i != N - 1) dptr = curno + M;
			if (j != M - 1) rptr = curno + 1;
			if (i == 0 || i == N - 1 || j == 0 || j == M - 1) nodes.push_back(make_pair(-1, make_pair(dptr, rptr)));
			else nodes.push_back(make_pair(a[i - 1][j - 1], make_pair(dptr, rptr)));
		}
	}
	while (Q--) {
		vector< pair< int, pair<int, int> > > intents;
		int xa, ya, xb, yb, sa, sb;
		scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &sa, &sb);
		int rootA = 0;
		rootA = advance_down(rootA, xa - 1);
		rootA = advance_right(rootA, ya - 1);
		int rootB = 0;
		rootB = advance_down(rootB, xb - 1);
		rootB = advance_right(rootB, yb - 1);
		
		for (int i = 0; i < sa; i++) {
			rootA = advance_down(rootA, 1);
			rootB = advance_down(rootB, 1);
			intents.push_back(make_pair(1, make_pair(rootA, rootB)));
		}
		for (int i = 0; i < sb; i++) {
			rootA = advance_right(rootA, 1);
			rootB = advance_right(rootB, 1);
			intents.push_back(make_pair(0, make_pair(rootA, rootB)));
		}
		rootA = rootB = 0;
		rootA = advance_down(rootA, xa - 1);
		rootA = advance_right(rootA, ya - 1);
		rootB = advance_down(rootB, xb - 1);
		rootB = advance_right(rootB, yb - 1);
		for (int i = 0; i < sb; i++) {
			rootA = advance_right(rootA, 1);
			rootB = advance_right(rootB, 1);
			intents.push_back(make_pair(0, make_pair(rootA, rootB)));
		}
		for (int i = 0; i < sa; i++) {
			rootA = advance_down(rootA, 1);
			rootB = advance_down(rootB, 1);
			intents.push_back(make_pair(1, make_pair(rootA, rootB)));
		}
		for (int i = 0; i < intents.size(); i++) {
			if (intents[i].first == 0) swap(nodes[intents[i].second.first].second.first, nodes[intents[i].second.second].second.first);
			else swap(nodes[intents[i].second.first].second.second, nodes[intents[i].second.second].second.second);
		}
	}
	int curnode = 0;
	for (int i = 0; i < N - 2; i++) {
		curnode = advance_down(curnode, 1);
		int tcur = curnode;
		for (int j = 0; j < M - 2; j++) {
			if (j) printf(" ");
			tcur = advance_right(tcur, 1);
			printf("%d", nodes[tcur].first);
		}
		printf("\n");
	}
}