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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R

class EulerTour {	//	0-indexed
public:
	vector<int>tour;
	vector<int>depth;
	vector<int>l;
	vector<int>r;
private:
	int node;
	vector<vector<int>>edge;
	int root = 0;
	void DFS(int n) {
		for (auto i : edge[n]) {
			if (depth[n] < depth[i]) {
				tour.push_back(n);
				DFS(i);
			}
		}
		tour.push_back(n);
		return;
	}
	void BFS() {
		for (auto &i : depth)i = MOD;
		depth[root] = 0;
		queue<int>Q;
		Q.push(root);
		while (!Q.empty()) {
			int cn = Q.front();
			int c = depth[cn];
			Q.pop();
			for (auto i : edge[cn]) {
				if (depth[i] > c + 1) {
					depth[i] = c + 1;
					Q.push(i);
				}
			}
		}
		return;
	}
public:
	EulerTour(int n, int ro) {
		node = n;
		node++;
		root = ro;
		edge.resize(node);
		depth.resize(node, MOD);
		l.resize(node, MOD);
		r.resize(node, 0);
		return;
	}
	void Add_Edge(int a, int b) {
		edge[a].push_back(b);
		edge[b].push_back(a);
		return;
	}
	void Retour() {
		if (!tour.empty())tour.clear();
		BFS();
		DFS(root);
		for (int i = 0; i < tour.size(); i++) {
			l[tour[i]] = min(l[tour[i]], i);
			r[tour[i]] = max(r[tour[i]], i);
		}
		return;
	}
};

class Segment_Tree {
	vector<long long int>v;
	vector<long long int>add;
	vector<long long int>modi;
	vector<int>l;
	vector<int>r;
	int num;
	long long int ret;
	bool is_min;
	void Left(int place) {
		if (place >= v.size() / 2) {
			l[place] = place - v.size() / 2;
			return;
		}
		Left(place * 2);
		Left(place * 2 + 1);
		l[place] = l[place * 2];
		return;
	}
	void Right(int place) {
		if (place >= v.size() / 2) {
			r[place] = place - v.size() / 2;
			return;
		}
		Right(place * 2);
		Right(place * 2 + 1);
		r[place] = r[place * 2 + 1];
		return;
	}
	long long int Update(int place) {
		if (place >= v.size() / 2) {
			return v[place];
		}
		if (is_min) {
			v[place] = min(Update(place * 2), Update(place * 2 + 1));
			return v[place];
		}
		v[place] = max(Update(place * 2), Update(place * 2 + 1));
		return v[place];
	}
	void Modify(int a, int b, long long int num, int place) {
		if (l[place] >= a && r[place] <= b) {
			modi[place] = num;
			v[place] = num;
			add[place] = 0;
			return;
		}
		if (l[place] > b || r[place] < a)return;
		if (modi[place] != LLONG_MAX) {
			modi[place * 2] = modi[place * 2 + 1] = modi[place];
			v[place * 2] = v[place * 2 + 1] = modi[place];
			add[place * 2] = add[place * 2 + 1] = 0;
			modi[place] = LLONG_MAX;
		}
		add[place * 2] += add[place];
		add[place * 2 + 1] += add[place];
		add[place] = 0;
		Modify(a, b, num, place * 2);
		Modify(a, b, num, place * 2 + 1);
		if (is_min)v[place] = min(v[place * 2] + add[place * 2], v[place * 2 + 1] + add[place * 2 + 1]);
		else v[place] = max(v[place * 2] + add[place * 2], v[place * 2 + 1] + add[place * 2 + 1]);
		return;
	}
	void Add(int a, int b, long long int num, int place) {
		if (l[place] >= a && r[place] <= b) {
			if (modi[place] != LLONG_MAX) {
				if (place * 2 < v.size()) {
					modi[place * 2] = modi[place * 2 + 1] = modi[place];
					v[place * 2] = v[place * 2 + 1] = modi[place];
					add[place * 2] = add[place * 2 + 1] = 0;
				}
				modi[place] = LLONG_MAX;
			}
			add[place] += num;
			return;
		}
		if (l[place] > b || r[place] < a)return;
		if (modi[place] != LLONG_MAX) {
			modi[place * 2] = modi[place * 2 + 1] = modi[place];
			v[place * 2] = v[place * 2 + 1] = modi[place];
			add[place * 2] = add[place * 2 + 1] = 0;
			modi[place] = LLONG_MAX;
		}
		add[place * 2] += add[place];
		add[place * 2 + 1] += add[place];
		add[place] = 0;
		Add(a, b, num, place * 2);
		Add(a, b, num, place * 2 + 1);
		if (is_min)v[place] = min(v[place * 2] + add[place * 2], v[place * 2 + 1] + add[place * 2 + 1]);
		else v[place] = max(v[place * 2] + add[place * 2], v[place * 2 + 1] + add[place * 2 + 1]);
		return;
	}
	void RMQ(int a, int b, int place) {
		if (l[place] >= a && r[place] <= b) {
			if (modi[place] != LLONG_MAX) {
				if (place * 2 < v.size()) {
					modi[place * 2] = modi[place * 2 + 1] = modi[place];
					v[place * 2] = v[place * 2 + 1] = modi[place];
					add[place * 2] = add[place * 2 + 1] = 0;
				}
				modi[place] = LLONG_MAX;
			}
			if (is_min)ret = min(ret, v[place] + add[place]);
			else ret = max(ret, v[place] + add[place]);
			return;
		}
		if (l[place]>b || r[place]<a) return;
		if (modi[place] != LLONG_MAX) {
			modi[place * 2] = modi[place * 2 + 1] = modi[place];
			v[place * 2] = v[place * 2 + 1] = modi[place];
			add[place * 2] = add[place * 2 + 1] = 0;
			modi[place] = LLONG_MAX;
		}
		add[place * 2] += add[place];
		add[place * 2 + 1] += add[place];
		add[place] = 0;
		RMQ(a, b, place * 2);
		RMQ(a, b, place * 2 + 1);
		if (is_min)v[place] = min(v[place * 2] + add[place * 2], v[place * 2 + 1] + add[place * 2 + 1]);
		else v[place] = max(v[place * 2] + add[place * 2], v[place * 2 + 1] + add[place * 2 + 1]);
		return;
	}
public:
	Segment_Tree(int n, bool min) {
		n++;
		num = 1;
		while (num < n * 2) {
			num *= 2;
		}
		l.resize(num);
		r.resize(num);
		is_min = min;
		if (min) {
			v.resize(num, MOD*MOD);
		}
		else v.resize(num, -MOD * MOD);
		add.resize(num, 0);
		modi.resize(num, MOD*MOD);
		Left(1);
		Right(1);
	}
	void Insert(int place, long long int num, bool update) {
		place += v.size() / 2;
		v[place] = num;
		if (!update)return;
		place /= 2;
		while (place) {
			if (is_min)v[place] = min(v[place * 2], v[place * 2 + 1]);
			else v[place] = max(v[place * 2], v[place * 2 + 1]);
			place /= 2;
		}
	}
	void Modify(int a, int b, long long int num) {
		Modify(a, b, num, 1);
	}
	void Add(int a, int b, long long int num) {
		Add(a, b, num, 1);
	}
	void Init() {
		Update(1);
	}
	long long int RMQ(int a, int b) {
		if (is_min)ret = LLONG_MAX;
		else ret = LLONG_MIN;
		RMQ(a, b, 1);
		return ret;
	}
};

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<int>v(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}
	EulerTour et(N, 1);
	vector<vector<int>>edge(N + 1);
	for (int i = 1; i < N; i++) {
		cin >> L >> R;
		edge[L].push_back(R);
		edge[R].push_back(L);
		et.Add_Edge(L, R);
	}
	vector<int>depth(N + 1, MOD);
	Calculate_Depth(edge, depth, 1);
	et.Retour();
	K = et.tour.size();
	Segment_Tree sg(K, true);
	sg.Modify(0, K, 0);
	for (int i = 1; i <= N; i++) {
		if(depth[i]%2)sg.Add(et.l[i], et.l[i], -v[i] );
		else sg.Add(et.l[i], et.l[i], v[i]);
	}
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			int b, c;
			cin >> b >> c;
			if(depth[b]%2)sg.Add(et.l[b] , et.r[b], -c);
			else sg.Add(et.l[b], et.r[b], c);
		}
		else {
			int b;
			cin >> b;
			if(depth[b]%2)cout << -sg.RMQ(et.l[b], et.l[b]) << endl;
			else cout << sg.RMQ(et.l[b], et.l[b]) << endl;
		}
	}
	return 0;
}