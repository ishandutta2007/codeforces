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
constexpr long double EPS = 1e-8;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;

bool func(vector<vector<int>>box, vector<vector<int>>in, vector<int>num,int st) {
	vector<int>ans;
	vector<int>used(N - 1);
	queue<int>Q;
	vector<int>flag(N + 1);
	for (int i = 1; i <= N; i++) {
		if (num[i] == 1) {
			if (i == st)continue;
			Q.push(i);
			flag[i] = 1;
			break;
		}
	}
	while (!Q.empty()) {
		if (Q.size() > 1) return false;
		int cn = Q.front();
		ans.push_back(cn);
		Q.pop();
		for (auto i : in[cn]) {
			if (used[i])continue;
			used[i] = 1;
			for (auto j : box[i]) {
				num[j]--;
				if (j == st) {
					if (ans.size() + box[i].size() != N + 1)return false;
					continue;
				}
				if (num[j] <= 1) {
					if (flag[j])continue;
					Q.push(j);
					flag[j] = 1;
				}
			}
		}
	}
	ans.push_back(st);
	if (ans.size() == N) {
		reverse(ans.begin(), ans.end());
		for (auto i : ans)cout << i << " ";
		cout << endl;
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N;
		vector<vector<int>>box(N - 1);
		vector<vector<int>>in(N + 1);
		vector<int>num(N + 1);
		for (int i = 0; i < N - 1; i++) {
			cin >> M;
			box[i].resize(M);
			for (auto &j : box[i]) {
				cin >> j;
				in[j].push_back(i);
				num[j]++;
			}
		}
		for (int i = 1; i <= N; i++) {
			if (func(box, in, num, i))break;
		}
	}
}