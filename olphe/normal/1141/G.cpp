#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;

struct Edge {
	int a, b, color;
};

struct Node {
	int dir, nxdir, index;
	bool operator <(const Node&n)const {
		return dir < n.dir || (dir == n.dir&&nxdir < n.nxdir);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<Edge>edge(N - 1);
	vector<vector<pair<int, int>>>nx(N);
	vector<int>dir(N);
	for (int i = 0; i < N-1; i++) {
		cin >> L >> R;
		L--;
		R--;
		dir[L]++;
		dir[R]++;
		edge[i].a = L;
		edge[i].b = R;
		nx[L].push_back({ R,i });
		nx[R].push_back({ L,i });
	}
	vector<Node>node(N);
	for (int i = 0; i < N; i++) {
		node[i].dir = dir[i];
		node[i].index = i;
	}
	for (auto i : edge) {
		node[i.a].nxdir = max(node[i.a].nxdir, dir[i.b]);
		node[i.b].nxdir = max(node[i.b].nxdir, dir[i.a]);
	}
	sort(node.begin(), node.end());
	reverse(node.begin(), node.end());
	vector<int>uni(N);
	for (int i = 0; i < K; i++) {
		uni[node[i].index]++;
	}
	vector<int>used(N);
	queue<int>Q;
	Q.push(0);
	vector<set<int>>box(N);
	vector<int>ans(N - 1);
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		used[cn]++;
		if (uni[cn]) {
			int c;
			if (box[cn].empty())c = 1;
			else c = *box[cn].begin();
			for (auto i : nx[cn]) {
				if (used[i.first])continue;
				Q.push(i.first);
				ans[i.second] = c;
				box[i.first].insert(c);
			}
		}
		else {
			int c = 1;
			for (auto i : nx[cn]) {
				if (used[i.first])continue;
				Q.push(i.first);
				while (box[cn].find(c) != box[cn].end())c++;
				ans[i.second] = c;
				box[i.first].insert(c);
				box[cn].insert(c);
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (auto j : box[i])ret = max(ret, j);
	}
	cout << ret << endl;
	for (auto i : ans)cout << i << " ";
	cout << endl;
	return 0;
}