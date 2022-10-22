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

//long long int N, M, K, H, W, L, R;
int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>p(N + 1);
	vector<vector<int>>edge(N + 1);
	for (int i = 2; i <= N; i++) {
		cin >> K;
		p[i] = K;
		edge[K].push_back(i);
	}
	vector<int>dir(N + 1);
	queue<int>Q;
	vector<int>ans;
	for (int i = 1; i <= N; i++) {
		dir[i] = edge[i].size();
		if (!dir[i])Q.push(i);
	}
	vector<int>leaf(N + 1);
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		if (edge[cn].empty()) {
			leaf[cn] = 1;
			ans.push_back(1);
			dir[p[cn]]--;
			leaf[p[cn]]++;
			if (!dir[p[cn]])Q.push(p[cn]);
		}
		else {
			ans.push_back(leaf[cn]);
			dir[p[cn]]--;
			leaf[p[cn]] += leaf[cn];
			if (!dir[p[cn]])Q.push(p[cn]);
		}
	}
	sort(ans.begin(), ans.end());
	for (auto i : ans)cout << i << " ";
}