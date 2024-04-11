#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <set>
#include <bitset>
#include <cmath>
#include <unordered_map>
#include <map>
#include <intrin.h>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


const int sz = 1e3 + 1;
int a[sz], n;
int dp[8][sz][sz];//starts from a, has b elements of kind c

bool check(int mn) {
	vector<int> v{ 1,2,3,4,5,6,7,8 };
	do {
		int ind = 0, pos = 0;
		bool bad = 0;
		while (ind < 8) {
			if (pos==n||dp[v[ind] - 1][pos][mn] == -1) {
				bad = 1;
				break;
			}
			else {
				pos = dp[v[ind] - 1][pos][mn] + 1;
				ind++;
			}
		}
		if (!bad)return true;
	} while (next_permutation(v.begin(), v.end()));
	return false;
}

void initDp() {
	foru(i, 0, 8) {
		foru(j, 0, n) {
			foru(k, 0, n)dp[i][j][k] = -1;
		}
	}
	foru(i, 0, 8) {
		int crcnt = 0;
		foru(j, 0, n) {
			if (a[j] == i + 1) {
				crcnt++;
				int tcnt = 0;
				ford(k, j, 0) {
					if (a[k] == i + 1)tcnt++;
					dp[i][k][tcnt] = j;
				}
			}
		}
	}
}

bool pos(int i, int amt) {
	vector<int> p{ 0,1,2,3,4,5,6,7};
	do {
		int ind = 0, crind = 0;
		bool bad = 0;
		while (ind < 8) {
			if (crind == n) {
				bad = 1;
				break;
			}
			int meamt = amt + ((i >> p[ind]) & 1);
			if (!meamt) {
				ind++;
				continue;
			}
			else if (dp[p[ind]][crind][meamt] != -1)crind = dp[p[ind]][crind][meamt] + 1;
			else {
				bad = 1;
				break;
			}
			ind++;
		}
		if (!bad)return true;
	} while (next_permutation(p.begin(), p.end()));
	return false;
}

int main() {
	fast;
	cin >> n;
	foru(i, 0, n)cin >> a[i];
	initDp();
	ll bst = 0, l = 1, r = n / 8, mid;
	while (l <= r) {
		mid = (l + r + 1) / 2;
		if (check(mid)) {
			bst = mid; l = mid + 1;
		}
		else r = mid - 1;
	}
	ll crbst = bst * 8;
	int bstextra = 0;
	foru(i, 0, 1 << 8) {
		int ppcnt = __popcnt(i);
		if (ppcnt <= bstextra)continue;
		if (pos(i, bst)) {
			if (bstextra < ppcnt) {
				bstextra = ppcnt;
			}
		}
	}
	cout << crbst + bstextra << endl;
	return 0;
}