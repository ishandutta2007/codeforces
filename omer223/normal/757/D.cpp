#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

inline void iadd(int& lhs, const int& rhs) {
	lhs = (lhs + rhs) % mod;
}

const int sz = 75, MAX_BITS = 5, BOUND = (1 << 20);
int a[sz], n;
int *ums[sz], *zes[sz];
int tot = 0;

void input() {
	string str;
	cin >> n >> str;
	foru(i, 0, n) a[i] = str[i] - '0';
}

int main() {
	fast;
	input();
	foru(i, 0, n) { //zeros
		int mynum = 0, j, msk = 0;
		ums[i] = (int*)calloc(BOUND, sizeof(int));
		zes[i] = (int*)calloc(BOUND, sizeof(int));
		for (j = i; j >= 0 && i - j < MAX_BITS; j--) {
			mynum |= (a[j] << (i - j));
			if (mynum > 20)break;
			else if (!mynum)continue;
			msk = (1 << (mynum - 1));
			iadd(ums[i][msk], 1);
			if (j != 0) {
				for (int k = 0; k < BOUND; k++)
					iadd(ums[i][msk | k], ums[j - 1][k]);
			}
		}
		if (mynum&&mynum <= 20) {
			for (j = i - MAX_BITS; j >= 0 && !a[j]; j--)
				iadd(ums[i][msk], 1);
			if (i - MAX_BITS - 1 >= 0 && a[i - MAX_BITS] == 0) {
				for (int k = 0; k < BOUND; k++)
					iadd(ums[i][msk | k], zes[i - MAX_BITS - 1][k]);
			}
		}
		if (a[i] || !i) {
			for (int k = 0; k < BOUND; k++)
				zes[i][k] = ums[i][k];
		}
		else {
			for (int k = 0; k < BOUND; k++) {
				zes[i][k] = (zes[i - 1][k] + ums[i][k]) % mod;
			}
		}
		for (int bits = 1; bits <= 20; bits++) {
			iadd(tot, ums[i][(1 << bits) - 1]);
		}
		if (i >= 10) {
			free(ums[i - 10]);
			free(zes[i - 10]);
		}
	}
	cout << tot << '\n';
	return 0;
}