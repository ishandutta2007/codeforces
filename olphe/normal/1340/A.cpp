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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N;
		vector<int>v(N);
		vector<int>p(N);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
			v[i] --;
			p[v[i]] = i;
		}
		int bef = -1;
		bool flag = true;
		for (int i = 0; i < N; i++) {
			if (bef == -1) {
			}
			else {
				if (p[i] != bef + 1)flag = false;
			}
			bef = p[i];
			if (bef + 1 == N || v[bef + 1] < i)bef = -1;
		}
		if (flag)cout << "Yes\n";
		else cout << "No\n";
	}
}