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

using namespace std;

const long long int MOD = 1000000007;


long long int N, M, K, H, W, L, R;

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	cin >> N;
	vector<int>v(N + 1);
	vector<int>place(N + 1);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &v[i]);
		place[v[i]] = i;
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (place[i] != i) {
			int av, ap, bv, bp;
			av = i;
			ap = place[i];
			bv = v[i];
			bp = place[v[i]];
			place[av] ^= place[bv];
			place[bv] ^= place[av];
			place[av] ^= place[bv];
			v[ap] ^= v[bp];
			v[bp] ^= v[ap];
			v[ap] ^= v[bp];
			cnt++;
		}
	}
	if (!((N * 3 - cnt) & 1)) {
		cout << "Petr" << endl;
	}
	else {
		cout << "Um_nik" << endl;
	}
	return 0;
}