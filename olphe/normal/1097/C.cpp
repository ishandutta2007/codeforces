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

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<string>s(N);
	for (auto &i : s)cin >> i;
	vector<int>ma(N, -MOD);
	vector<int>mi(N, MOD);
	vector<int>v(N);
	vector<int>box(2000001);
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (auto j : s[i]) {
			if (j == '(')cnt++;
			else cnt--;
			ma[i] = max(ma[i], cnt);
			mi[i] = min(mi[i], cnt);
		}
		v[i] = cnt;
		if (v[i] > 0) {
			if (mi[i] >= 0)box[v[i] + 1000000]++;
		}
		else if (v[i] == 0) {
			if (mi[i] >= 0)box[1000000]++;
		}
		else {
			if (mi[i] == v[i])box[1000000 + v[i]]++;
		}
		//cout << v[i] << endl;
	}
	int ans = 0;
	for (int i = 1; i < 1000000; i++) {
		ans += min(box[i], box[2000000 - i]);
	}
	//cout << ans << endl;
	ans += box[1000000] / 2;
	cout << ans << endl;
	return 0;
}