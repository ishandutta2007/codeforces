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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	auto P = Prime(N);
	while (P.back() > N)P.pop_back();
	vector<int>bag(N + 1);
	for (int i = 2; i <= N; i++) {
		int box = i;
		int m = 0;
		for (auto j : P) {
			if (j*j > box)break;
			if (box%j == 0) {
				box /= j;
				break;
			}
		}
		bag[box]++;
	}
	vector<int>ans(N + 1);
	int num = 1;
	for (auto i : P) {
		num++;
		ans[num] = 1;
		bag[i]--;
	}
	for(int i=2;i<=N;i++){
		for (int j = num + 1; j <= num + bag[i]; j++) {
			ans[j] = i;
		}
		num += bag[i];
	}
	for (int i = 2; i <= N; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}