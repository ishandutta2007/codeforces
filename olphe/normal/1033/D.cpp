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

using namespace std;

const long long int MOD = 998244353;

long long int N, M, K, H, W, L, R;

long long int gcd(long long int a, long long int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	map<long long int, long long int>m;
	vector<long long int>v(N);
	vector<long long int>four;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		L = 0;
		R = 1000000007LL * 3 / 2;
		while (R - L > 1) {
			long long int mid = (R + L + 1) / 2;
			if (mid*mid < v[i])L = mid;
			else R = mid;
		}
		if (R*R == v[i]) {
			long long int box = R;
			L = 0;
			R = 1000000007LL * 3 / 2;
			while (R - L>1) {
				long long int mid = (R + L + 1) / 2;
				if (mid*mid < box)L = mid;
				else R = mid;
			}
			if (R*R == box) {
				m[R] += 4;
			}
			else {
				m[box] += 2;
			}
			continue;
		}
		L = 0;
		R = 1300000;
		while (R - L > 1) {
			long long int mid = (R + L + 1) / 2;
			if (mid*mid*mid < v[i])L = mid;
			else R = mid;
		}
		if (R*R*R == v[i]) {
			m[R] += 3;
			continue;
		}
		four.push_back(i);
	}
	long long int cnt = -1;
	map<long long int, pair<long long int, long long int>>used;
	for (auto i : four) {
		bool flag = true;
		bool same = false;
		for (int j = 0; j < N; j++) {
			if (i == j)continue;
			if (v[i] == v[j]) {
				same = true;
				if (i > j) {
					m[used[v[i]].second]++;
					m[used[v[i]].first]++;
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			for (int j = 0; j < N; j++) {
				if (v[i] == v[j])continue;
				long long int box = gcd(v[i], v[j]);
				if (box > 1) {
					if (same) {
						flag = false;
						m[box]++;
						m[v[i] / box]++;
						used[v[i]] = { box,v[i] / box };
						break;
					}
					else {
						flag = false;
						m[box]++;
						m[v[i] / box]++;
						break;
					}
				}
			}
		}
		if (flag){
			m[cnt]++;
			cnt--;
			m[cnt]++;
			cnt--;
			if (same) {
				used[v[i]] = { cnt + 1,cnt + 2 };
			}
		}
	}
	long long int ans = 1;
	for (auto i : m) {
		//cout << i.first << " " << i.second << endl;
		ans *= (i.second+1);
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}