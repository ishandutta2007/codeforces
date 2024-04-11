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
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	map<int, int>mp;
	for (auto &i : v) {
		cin >> i;
		mp[i]++;
	}
	vector<vector<int>>box(N + 1);
	vector<int>num(N + 1);
	for (auto i : mp) {
		num[i.second]++;
		box[i.second].push_back(i.first);
	}
	int ov = 0;
	long long int sum = N;
	for (int i = N; i >= 1; i--) {
		int nh = i, nw = sum / i;
		if (nh <= nw && nh*nw >= H * W) {
			H = nh, W = nw;
		}
		ov += num[i];
		sum -= ov;
	}
	cout << H * W << endl;
	cout << H << " " << W << endl;
	vector<int>w;
	for (int i = N; i >= 1; i--) {
		for (auto j : box[i]) {
		//	cout << i << " " << j << endl;
			for (int k = 0; k < min((int)H, i); k++) {
				//cout << j << endl;
				if (w.size() < H*W)w.push_back(j);
			}
		}
	}
	reverse(w.begin(), w.end());
	vector<vector<int>>ans(H, vector<int>(W));
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			ans[j][(i + j) % W] = w.back();
			w.pop_back();
		}
	}
	for (auto i : ans) {
		for (auto j : i)cout << j << " ";
		cout << endl;
	}
}