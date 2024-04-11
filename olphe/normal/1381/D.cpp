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
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int length = 0;

void Calculate_Depth(vector<vector<int>>&edge, vector<int>&depth, int stnode) {
	depth[stnode] = 0;
	queue<int>Q;
	Q.push(stnode);
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		for (auto i : edge[cn]) {
			if (depth[i] > depth[cn] + 1) {
				depth[i] = depth[cn] + 1;
				Q.push(i);
			}
		}
	}
	return;
}

int Search(vector<vector<int>>&edge, vector<int>&dis, vector<int>&leg, int node) {
	int ret = 0;
	for (auto i : edge[node]) {
		if (dis[i] <= dis[node])continue;
		int box = Search(edge, dis, leg, i);
		leg[node] += box >= length;
		ret = max(box, ret);
	}
	ret++;
	return ret;
}

int Search(vector<vector<int>>&edge, vector<int>&dis, vector<int>&leg, vector<int>&can, int node) {
	int ret = 0;
	for (auto i : edge[node]) {
		if (dis[i] <= dis[node])continue;
		int box = Search(edge, dis, leg,can, i);
		ret = max(box, ret);
	}
	can[node] = ret;
	ret++;
	return ret;
}

class Lowest_Common_Ancestor {
	vector<vector<int>>edge;
	int height = 0;
	int node;
public:
	vector<int>depth;
	vector<vector<int>>parent;
	Lowest_Common_Ancestor(int num) {
		num++;
		node = num;
		while (num) {
			height++;
			num /= 2;
		}
		parent.resize(height);
		edge.resize(node);
		depth.resize(node);
		for (int i = 0; i < height; i++)parent[i].resize(node);
	}
	void Add_Edge(int a, int b) {
		edge[a].push_back(b);
		edge[b].push_back(a);
		return;
	}
	void Update(int rtnode) {
		queue<int>QQ;
		for (int i = 0; i < node; i++) depth[i] = INT_MAX;
		depth[rtnode] = 0;
		QQ.push(rtnode);
		while (!QQ.empty()) {
			int c = QQ.front();
			for (auto i : edge[c]) {
				if (depth[i] > depth[c] + 1) {
					depth[i] = depth[c] + 1;
					QQ.push(i);
				}
			}
			QQ.pop();
		}
		parent[0][rtnode] = -1;
		for (int i = 0; i < node; i++) {
			for (auto j : edge[i]) {
				if (depth[i] - 1 == depth[j]) {
					parent[0][i] = j;
					break;
				}
			}
		}
		for (int i = 0; i < height - 1; i++) {
			for (int j = 0; j < node; j++) {
				if (parent[i][j] < 0)parent[i + 1][j] = -1;
				else parent[i + 1][j] = parent[i][parent[i][j]];
			}
		}
		return;
	}
	int LCA(int u, int v) {
		if (depth[u] > depth[v])swap(u, v);
		for (int i = 0; i < height; i++) {
			if ((depth[v] - depth[u]) >> i & 1) {
				v = parent[i][v];
			}
		}
		if (u == v)return u;
		for (int i = height - 1; i >= 0; i--) {
			if (parent[i][v] != parent[i][u]) {
				u = parent[i][u];
				v = parent[i][v];
			}
		}
		return parent[0][u];
	}
	int Dist(int u, int v) {
		return depth[u] + depth[v] - depth[LCA(u, v)] * 2;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N >> L >> R;
		L--, R--;
		Lowest_Common_Ancestor lca(N);
		vector<vector<int>>edge(N);
		for (int i = 1; i < N; i++) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			lca.Add_Edge(a, b);
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		vector<int>dis(N, MOD);
		Calculate_Depth(edge, dis, L);
		length = dis[R];
		vector<int>adis(N, MOD);
		Calculate_Depth(edge, adis, 0);
		int bdir = 0;
		for (int i = 1; i < N; i++) {
			if (adis[i] > adis[bdir])bdir = i;
		}
		vector<int>bdis(N, MOD);
		Calculate_Depth(edge, bdis, bdir);
		int adir = 0;
		for (int i = 1; i < N; i++) {
			if (bdis[i] > bdis[adir])adir = i;
		}
		for (auto &i : adis)i = MOD;
		Calculate_Depth(edge, adis, adir);
		vector<int>on_dir(N);
		for (int i = 0; i < N; i++) {
			if (adis[i] + bdis[i] == adis[bdir])on_dir[i] = 1;
		}
		vector<int>cdis(N, MOD);
		queue<int>Q;
		for (int i = 0; i < N; i++) {
			if (on_dir[i]) {
				Q.push(i);
				cdis[i] = 0;
			}
		}
		while (!Q.empty()) {
			int cn = Q.front();
			Q.pop();
			for (auto i : edge[cn]) {
				if (cdis[i] > cdis[cn] + 1) {
					cdis[i] = cdis[cn] + 1;
					Q.push(i);
				}
			}
		}
		vector<int>leg(N);
		for (int i = 0; i < N; i++) {
			if (cdis[i] == 0) {
				leg[i] += adis[i] >= length;
				leg[i] += bdis[i] >= length;
				Search(edge, cdis, leg, i);
			}
			else {
				leg[i] += max(adis[i], bdis[i]) + cdis[i] >= length;
			}
		}
		//	for (int i = 0; i < N; i++) {
		//		cout << i << " " << leg[i] << endl;
		//	}
		int root = -1;
		for (int i = 0; i < N; i++) {
			if (leg[i] >= 3) {
				root = i;
			}
		}
		if (root == -1) {
			cout << "NO\n";
			continue;
		}
		for (auto &i : dis)i = MOD;
		Calculate_Depth(edge, dis, root);
		vector<int>can(N);
		Search(edge, dis, leg, can, root);
		//	for (int i = 0; i < N; i++) {
		//		cout << i << " " << can[i] << endl;
		//	}
		lca.Update(root);
		int goal = lca.LCA(L, R);
		if (L == goal || R == goal) {
			cout << "YES\n";
			continue;
		}
		vector<pair<int, int>>vp;
		vp.push_back({ dis[L],R });
		vp.push_back({ L,dis[R] });
		bool flag = false;
		int Ltp = L, Rtp = R;
		int step = 0;
		int dissum = lca.depth[L] + lca.depth[R];
	//	cout << "root " << root << endl;
	//	cout << "dissum " << dissum << endl;
		while (1) {
			step++;
			if (dissum - (can[L] + lca.depth[L]) <= lca.depth[goal]) {
				flag = true;
				break;
			}
			if (dissum - (can[R] + lca.depth[R]) <= lca.depth[goal]) {
				flag = true;
				break;
			}
			if (step & 1) {
				int box = -(dissum - can[L] - lca.depth[L] - lca.depth[R]);
			//	cout << "box " << box << endl;
				pair<int, int>in;
				in.first = L;
				for (int i = 0; i < lca.parent.size(); i++) {
					if ((box >> i) & 1) {
						R = lca.parent[i][R];
					}
				}
				in.second = R;
				vp.push_back(in);
			}
			else {
				int box = -(dissum - can[R] - lca.depth[L] - lca.depth[R]);
			//	cout << "box " << box << endl;
				pair<int, int>in;
				in.second = R;
				for (int i = 0; i < lca.parent.size(); i++) {
					if ((box >> i) & 1) {
						L = lca.parent[i][L];
					}
				}
				in.first = L;
				vp.push_back(in);
			}
			if (L == goal || R == goal) {
				flag = true;
				break;
			}
			if (vp[step + 1] == vp[step - 1] && step >= 2)break;
		}
		for (int i = 0; i < N; i++) {
			if (leg[i] < 3)continue;
			if (lca.LCA(i, Ltp) == Ltp)flag = true;
			if (lca.LCA(i, Rtp) == Rtp)flag = true;
		}
		if (flag) {
			cout << "YES\n";
			continue;
		}
		else {
			cout << "NO\n";
			continue;
		}
	}
}