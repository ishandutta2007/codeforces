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
	vector<long long int>v(N);
	vector<long long int>sum(N);
	for (auto &i : v)cin >> i;
	M = accumulate(v.begin(), v.end(), 0LL);
	vector<map<int, int>>mp(N);
	cin >> K;
	for (int i = 0; i < K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, c--;
		//cout << a << " " << b << " " << c << endl;
		if (mp[a].find(b) == mp[a].end()) {
			if (c >= 0) {
				mp[a][b] = c;
				sum[c]++;
				if (sum[c] <= v[c])M--;
			}
		}
		else {
			if (c == -1) {
				sum[mp[a][b]]--;
				if (sum[mp[a][b]] < v[mp[a][b]])M++;
				mp[a].erase(b);
			}
			else {
				sum[mp[a][b]]--;
				if (sum[mp[a][b]] < v[mp[a][b]])M++;
				mp[a][b] = c;
				sum[c]++;
				if (sum[c] <= v[c])M--;
			}
		}
		cout << M << endl;
	}
}