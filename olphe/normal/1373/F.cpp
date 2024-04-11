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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N;
		vector<long long int>v(N);
		vector<long long int>w(N);
		for (auto &i : v)cin >> i;
		for (auto &i : w)cin >> i;
		L = -1, R = w[0] + 1;
		while (R - L > 1) {
			long long int mid = (R + L) / 2;
			long long int amari = w[0] - mid;
			bool flag = true;
			for (int i = 1; i < N; i++) {
				if (v[i] - amari > w[i]) {
					flag = false;
					break;
				}
				else {
					amari = w[i] - (v[i] - amari);
				}
			}
			if (flag)L = mid;
			else R = mid;
		}
		if (L == -1) {
			cout << "NO\n";
			continue;
		}
		long long int amari = w[0] - L;
		bool flag = true;
		for (int i = 1; i < N; i++) {
			if (v[i] - amari > w[i]) {
				flag = false;
				break;
			}
			else {
				amari = w[i] - max(0LL,(v[i] - amari));
			}
		}
		if (amari + L < v[0])flag = false;
		if (flag)cout << "YES\n";
		else cout << "NO\n";
	}
}