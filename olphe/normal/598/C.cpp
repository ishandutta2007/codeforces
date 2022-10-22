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

using namespace std;

const long long  int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<pair<long double, int>>v(N);
	for (int i = 0; i < N; i++) {
		cin >> W >> H;
		v[i].first = atan2((long double)H, (long double)W);
		v[i].second = i + 1;
		//cout << v[i].first << endl;
	}
	int st = 1;
	sort(v.begin(), v.end());
	for (int i = 1; i < N; i++) {
		if (v[i].first - v[i - 1].first < v[st].first - v[st - 1].first)st = i;
	}
	if (v[0].first + (long double)3.1415926535897932384626433 * 2 - v.back().first < v[st].first-v[st-1].first)st = 0;
	int gl = (st + N - 1) % N;
	cout << v[st].second << " " << v[gl].second << endl;
	return 0;
}