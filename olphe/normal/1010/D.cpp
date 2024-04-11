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

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 1e-8;

long long int N, M, K, H, W, L, R;

inline int Search(vector<string>& s, vector<vector<int>>& v, vector<int>&num, int node) {
	//cout << node << endl;
	if (num[node] != -1) {
		return num[node];
	}
	if (s[node] == "AND") {
		num[node] = Search(s, v, num, v[node][0])&Search(s, v, num, v[node][1]);
		return num[node];
	}
	if (s[node] == "OR") {
		num[node] = Search(s, v, num, v[node][0]) | Search(s, v, num, v[node][1]);
		return num[node];
	}
	if (s[node] == "XOR") {
		num[node] = Search(s, v, num, v[node][0]) ^ Search(s, v, num, v[node][1]);
		return num[node];
	}
	if (s[node] == "NOT") {
		num[node] = 1 - Search(s, v, num, v[node][0]);
		return num[node];
	}
}

inline void Change(vector<string>& s, vector<vector<int>>& v, vector<int>&num, vector<int>& parent, vector<bool>&flag, int node) {
	//cout << node << endl;
	int p = parent[node];
	int brother = node;
	for (auto i : v[p])brother ^= i;
	//cout << p << endl;
	//cout << brother << endl;
	if (!brother) {
		if (flag[p]) {
			flag[node] = true;
		}
		if (s[node] != "IN") {
			for (auto i : v[node]) {
				Change(s, v, num, parent, flag, i);
			}
		}
	}
	else {
		int ret = 1 - num[node];
		if (s[p] == "AND") {
			ret &= num[brother];
			if (ret != num[p] && flag[p]) {
				flag[node] = true;
			}
		}
		if (s[p] == "OR") {
			ret |= num[brother];
			if (ret != num[p] && flag[p]) {
				flag[node] = true;
			}
		}
		if (s[p] == "XOR") {
			ret ^= num[brother];
			if (ret != num[p] && flag[p]) {
				flag[node] = true;
			}
		}
		if (s[node] != "IN") {
			for (auto i : v[node]) {
				Change(s, v, num, parent, flag, i);
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<string>s(N + 1);
	vector<vector<int>>v(N+1);
	vector<int>num(N + 1, -1);
	vector<int>parent(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> s[i];
		if (s[i] != "NOT"&&s[i] != "IN") {
			cin >> M >> K;
			v[i].push_back(M);
			v[i].push_back(K);
			parent[M] = i;
			parent[K] = i;
		}
		else {
			cin >> M;
			v[i].push_back(M);
			if (s[i] == "IN") {
				num[i] = M;
			}
			parent[M] = i;
		}
	}
	Search(s, v, num, 1);
	vector<bool>flag(N + 1, false);
	flag[1] = true;
	//cout << "hji";
	for (auto i : v[1]) {
		Change(s, v, num, parent, flag, i);
	}
	//for (int i = 1; i <= N; i++)cout << s[i] << endl;
	for (int i = 1; i <= N; i++) {
		if (s[i] == "IN") {
			if (!num[1]) {
				cout << !!flag[i];
			}
			else {
				cout << !flag[i];
			}
		}
	}
	cout << endl;
	return 0;
}