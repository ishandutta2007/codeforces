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
#include "functional"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

constexpr long long int border = 100000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<long long int>v(100001,1);
	for (int i = 1; i <= 100000; i++) {
		for (int j = 0; j < K; j++) {
			v[i] = min(v[i] * i, border+1);
		}
	}
	long long int ans = 0;
	map<long long int, long long int>mp;
	for (int i = 0; i < N; i++) {
		cin >> M;
		long long int by = 1;
		int box = M;
		for (int j = 2; j*j <= box; j++) {
			int num = 0;
			while (box%j == 0) {
				num++;
				box /= j;
			}
			if (num % K) {
				for (int k = 0; k < K - (num%K); k++) {
					by *= j;
					if (by > border)break;
				}
			}
		}
		if (box > 1) {
			for (int j = 0; j < K - 1; j++) {
				by *= box;
				if (by > border)break;
			}
		}
		for (int j = 1; j <= 100000; j++) {
			if (v[j] * by > border)break;
		//	cout << v[j] << " " << by << endl;
			auto it = mp.find(v[j] * by);
			if (it == mp.end())continue;
			ans += it->second;
		}
		mp[M]++;
	//	cout << i << " " << ans << endl;
	}
	cout << ans << endl;
}