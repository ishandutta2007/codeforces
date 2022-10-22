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
constexpr long double EPS = 1e-12;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N;
		vector<int>v(N);
		for (auto &i : v)cin >> i;
		vector<int>w({2,3,5,7,11,13,17,19,23,29,31});
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 11; j++) {
				if (v[i] % w[j] == 0) {
					v[i] = j;
					break;
				}
			}
		}
		map<int, int>mp;
		for (auto i : v)mp[i] = 0;
		int cnt = 1;
		for (auto &i : mp)i.second = cnt++;
		for (auto &i : v)i = mp[i];
		cout << mp.size() << endl;
		for (auto i : v)cout << i << " ";
		cout << endl;
	}
}