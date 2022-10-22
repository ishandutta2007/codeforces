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
#include "ctime"

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

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
	vector<map<int, int>>edge(N + 1);
	vector<vector<int>>e(N + 1);
	for (int i = 1; i < N; i++) {
		cin >> L >> R;
		edge[L][R] = 1;
		edge[R][L] = 1;
		e[L].push_back(R);
		e[R].push_back(L);
	}
	queue<int>Q;
	vector<int>dir(N + 1);
	vector<int>v(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> L;
		v[L]++;
		if (M == 1) {
			cout << L << endl;
			cout << 0 << endl;
			return 0;
		}
	}
	for (int i = 1; i <= N; i++) {
		dir[i] = edge[i].size();
		if (dir[i] == 1 && !v[i])Q.push(i);
	}
	K = N;
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		auto box = *edge[cn].begin();
		dir[cn] = 0;
		dir[box.first]--;
		edge[cn].clear();
		edge[box.first].erase(cn);
		if (dir[box.first] == 1&&!v[box.first]) {
			Q.push(box.first);
		}
		K--;
	}
	vector<int>dis(N + 1, MOD);
	for (int i = 1; i <= N; i++) {
		if (dir[i]) {
			Calculate_Depth(e, dis, i);
			break;
		}
	}
	int st = 1;
	for (int i = 1; i <= N; i++) {
		if (!dir[st])st = i;
		else if (dir[i]&&dis[st] < dis[i])st = i;
	}
	dis.assign(N + 1, MOD);
	Calculate_Depth(e, dis, st);
	int index = 1;
	for (int i = 1; i <= N; i++) {
		if (!dir[index])index = i;
		else if (dir[i]&&dis[index] < dis[i])index = i;
	}
	int minus = dis[index];
	int hoge = 1;
	dis.assign(N + 1, MOD);
	Calculate_Depth(e, dis, index);
	for (int i = 1; i <= N; i++) {
		if (!dir[hoge])hoge = i;
		else if (dir[i] && dis[hoge] < dis[i])hoge = i;
	}
	cout << min({ st,index,hoge }) << endl;
	cout << K * 2 - minus - 2 << endl;
	return 0;
}