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
#include "ctime"

using namespace std;

const long long int MOD = 1000000007;
//const long long  int MOD = 998244353;
//long long int N, M, K, H, W, L, R;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	vector<int>v(N);
	vector<int>w(M);
	for (auto &i : v) {
		cin >> i;
		i = min(i, int(N + M));
	}
	for (auto &i : w) {
		cin >> i;
		i = min(i, int(N + M));
	}
	sort(v.begin(), v.end());
	vector<pair<int, int>>p(M);
	for (int i = 0; i < M; i++) {
		p[i] = { w[i],i + 1 };
	}
	vector<int>u(N + M + 1);
	sort(w.begin(), w.end(), greater<int>());
	L = 0;
	R = M + 1;
	while (R - L > 1) {
		int mid = (R + L + 1) / 2;
		for (auto &i : u)i = 0;
		for (auto i : v)u[i]++;
		for (int i = 0; i < mid; i++) u[w[i]]++;
		bool flag = true;
		int cnt = 0;
		for (int i = 0; i <= N+M; i ++) {
			cnt += u[i];
			if (i < (cnt - 1) / K)flag = false;
		}
		if (flag)L = mid;
		else R = mid;
	}
	if (!L) {
		for (auto &i : u)i = 0;
		for (auto i : v)u[i]++;
		bool flag = true;
		int cnt = 0;
		for (int i = 0; i <= N + M; i++) {
			cnt += u[i];
			if (i < (cnt - 1) / K)flag = false;
		}
		if (!flag)cout << -1 << endl;
		else cout << 0 << endl << endl;
		return 0;
	}
	cout << L << endl;
	sort(p.begin(), p.end(), greater<pair<int,int>>());
	for (int i = 0; i < L; i++)cout << p[i].second << " ";
	cout << endl;
	return 0;
}