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

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

struct StronglyConnectedComponents {
	vector<vector<int>>new_edge;
	vector<int>new_node;
	StronglyConnectedComponents(const vector<vector<int>>&edge) {
		Initialize(edge);
		Compose_Reverse_Edge(edge);
		FirstDFS(edge);
		SecondDFS();
		Compose_New_Edge(edge);
	}
	void Debug() {
		for (int i = 0; i < num; i++) {
			cout << i << " " << first_DFS[i] << endl;
		}
		for (int i = 0; i < num; i++) {
			cout << i << " " << second_DFS[i] << endl;
		}
	}
private:
	int num = 0;
	int cnt = 0;
	vector<int>first_DFS;
	vector<int>second_DFS;
	vector<vector<int>>rev_edge;
	void Initialize(const vector<vector<int>>&edge) {
		num = edge.size();
		rev_edge.resize(num);
		first_DFS.resize(num);
		second_DFS.resize(num);
		new_node.resize(num);
	}
	void Compose_Reverse_Edge(const vector<vector<int>>&edge) {
		for (int i = 0; i < num; i++) {
			for (auto j : edge[i]) {
				rev_edge[j].push_back(i);
			}
		}
	}
	void FirstDFS(const vector<vector<int>>&edge) {
		vector<int>used(num);
		for (int i = 0; i < num; i++) {
			if (used[i])continue;
			used[i] = 1;
			DFS(edge, used, i);
		}
	}
	void DFS(const vector<vector<int>>&edge, vector<int>&used, int node) {
		for (auto i : edge[node]) {
			if (used[i])continue;
			used[i] = 1;
			DFS(edge, used, i);
		}
		first_DFS[node] = cnt++;
	}
	void SecondDFS() {
		vector<int>pri(num);
		for (int i = 0; i < num; i++) {
			second_DFS[i] = i;
		}
		for (int i = 0; i < num; i++)pri[first_DFS[i]] = i;
		for (int i = num - 1; i >= 0; i--) {
			if (second_DFS[i] != i)continue;
			DFS(pri[i], i);
		}
	}
	void DFS(int node, int maxnum) {
		for (auto i : rev_edge[node]) {
			if (second_DFS[first_DFS[i]] == maxnum)continue;
			if (first_DFS[i] > maxnum)continue;
			second_DFS[first_DFS[i]] = maxnum;
			DFS(i, maxnum);
		}
	}
	void Compose_New_Edge(const vector<vector<int>>&edge) {
		map<int, int>converter;
		for (int i = 0; i < num; i++) {
			converter[second_DFS[i]];
		}
		new_edge.resize(converter.size());
		cnt = 0;
		for (auto &i : converter)i.second = cnt++;
		for (int i = 0; i < num; i++) {
			new_node[i] = converter[second_DFS[first_DFS[i]]];
		}
		for (int i = 0; i < num; i++) {
			for (auto j : edge[i]) {// if you want jiko loop , ijiru this loop
				if (new_node[i] != new_node[j])new_edge[new_node[i]].push_back(new_node[j]);
			}
		}
		for (int i = 0; i < new_edge.size(); i++) {
			sort(new_edge[i].begin(), new_edge[i].end());
			new_edge[i].erase(unique(new_edge[i].begin(), new_edge[i].end()), new_edge[i].end());
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		string s;
		cin >> s;
		vector<vector<int>>edge(N);
		for (int i = 0; i < N; i++) {
			int nx = i + 1;
			nx %= N;
			if (s[i] == '-') {
				edge[i].push_back(nx);
				edge[nx].push_back(i);
			}
			else if (s[i]=='>') {
				edge[i].push_back(nx);
			}
			else {
				edge[nx].push_back(i);
			}
		}
		StronglyConnectedComponents scc(edge);
		int ans = 0;
		vector<int>num(N);
		for (int i = 0; i < N; i++) {
	//		cout << i << " " << scc.new_node[i] << endl;
			num[scc.new_node[i]]++;
		}
		for (int i = 0; i < N; i++) {
			ans += num[scc.new_node[i]] > 1;
		}
		cout << ans << endl;
	}
}