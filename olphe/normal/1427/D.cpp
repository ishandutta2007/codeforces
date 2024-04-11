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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	vector<vector<int>>ans;
	while (1) {
		vector<int>p(N + 1);
		for (int i = 0; i < N; i++) {
			p[v[i]] = i;
		}
		vector<int>w;
		for (int i = 1; i < N; i++) {
			if (p[i] > p[i + 1]) {
				w.push_back(p[i + 1]);
				int num = 0;
				for (int j = p[i+1], k = 0; j < N; j++, k++) {
					if (v[j] == i+1+k)num++;
					else break;
				}
				w.push_back(num);
				w.push_back(p[i] - p[i + 1] + 1 - num);
				w.push_back(N - p[i] - 1);
				break;
			}
		}
		if (w.empty())break;
	//	for (auto i : w)cout << i << " ";
	//	cout << endl;
		ans.push_back(vector<int>(0));
		for (auto i : w) {
			if (i)ans.back().push_back(i);
		}
		vector<vector<int>>nv;
		int sum = 0;
		for (auto i : ans.back()) {
			nv.push_back(vector<int>(0));
			for (int j = sum; j < sum + i; j++) {
				nv.back().push_back(v[j]);
			}
			sum += i;
		}
		reverse(nv.begin(), nv.end());
		v.clear();
		for (auto i : nv)for (auto j : i)v.push_back(j);
	//	for (auto i : v)cout << i << " ";
	//	cout << endl;
	}
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i.size();
		for (auto j : i)cout << " " << j;
		cout << endl;
	}
}