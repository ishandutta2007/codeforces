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

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;
int ans = MOD;

vector<int> Prime(int num) {
	vector<int>ret;
	ret.push_back(2);
	ret.push_back(3);
	for (int i = 5; i <= num; i += 6) {
		bool flag = true;
		for (int j = 2; j < ret.size(); j++) {
			if (ret[j] * ret[j] > i)break;
			if (i%ret[j] == 0) {
				flag = false;
				break;
			}
		}
		if (flag)ret.push_back(i);
		flag = true;
		for (int j = 2; j < ret.size(); j++) {
			if (ret[j] * ret[j] > i + 2)break;
			if ((i + 2) % ret[j] == 0) {
				flag = false;
				break;
			}
		}
		if (flag)ret.push_back(i + 2);
	}
	return ret;
}

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
			else if(depth[i]>=depth[cn]) {
				ans = min(depth[i] + depth[cn] + 1,ans);
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	auto P = Prime(1000000);
	vector<int>conv(1000001, -1);
	for (int i = 0; i < P.size(); i++) {
		conv[P[i]] = i;
	}
	conv[1] = P.size();
	vector<vector<int>>edge(P.size() + 1);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M;
		vector<int>box;
		for (int j = 0; P[j] * P[j] <= M; j++) {
			while (M%P[j]==0) {
				if (box.size() && box.back() == j)box.pop_back();
				else box.push_back(j);
				M /= P[j];
			}
		}
		if (M > 1)box.push_back(conv[M]);
		if (box.size() == 0) {
			cout << 1 << endl;
			return 0;
		}
		else if (box.size() == 1) {
			edge[conv[1]].push_back(box.back());
			edge[box.back()].push_back(conv[1]);
		}
		else {
			edge[box.front()].push_back(box.back());
			edge[box.back()].push_back(box.front());
		}
		
	}
	for (int i = 0; i <= P.size(); i++) {
		sort(edge[i].begin(), edge[i].end());
		for (int j = 1; j < edge[i].size(); j++) {
			if (edge[i][j] == edge[i][j - 1]) {
				cout << 2 << endl;
				return 0;
			}
		}
	}
	for (int i = 0; i < 200; i++) {
	//	cout << i << endl;
		vector<int>dis(P.size()+1, MOD);
		Calculate_Depth(edge, dis, i);
	}
	vector<int>dis(P.size()+1, MOD);
	Calculate_Depth(edge, dis, P.size());
	if (ans == MOD)ans = -1;
	cout << ans << endl;
}