#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

constexpr int MOD = (int)1e9 + 7;
constexpr int MAXVAL = (int)2e5;

multiset<int> mst[MAXVAL + 1];

inline int lgput(int a, int b) {
	int ans = 1;
	while (b > 0) {
		if (b & 1) ans = (1LL * ans * a) % MOD;
		b >>= 1;
		a = (1LL * a * a) % MOD;
	}
	return ans;
}


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	
	int n, q;
	cin >> n >> q;

	vector<unordered_map<int, int>> count(n);

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;

		int d = 2;
		while (d * d <= val) {
			int e = 0;
			while (val % d == 0) {
				val /= d;
				e++;
			}
			if (e > 0) {
				count[i][d] += e;
			}
			d++;
		}
		if (val > 1) {
			count[i][val]++;
		}
		for (auto itr : count[i]) {
			mst[itr.first].insert(itr.second);
		}
	}
	
	int answer = 1;
	for (int i = 2; i <= MAXVAL; i++) {
		if ((int)mst[i].size() == n) {
			answer = (1LL * answer * lgput(i, *mst[i].begin())) % MOD;
		}
	}

	while (q--) {
		int pos, val;
		cin >> pos >> val;
		pos--;

		vector<pair<int, int>> divi;

		int d = 2;
		while (d * d <= val) {
			int e = 0;
			while (val % d == 0) {
				val /= d;
				e++;
			}
			if (e > 0) {
				divi.emplace_back(d, e);
			}
			d++;
		} 
		if (val > 1) {
			divi.emplace_back(val, 1);
		}

		for (auto itr : divi) {
			if ((int)mst[itr.first].size() == n) {
				int exp = (1LL * (MOD - 2) * (*mst[itr.first].begin())) % (MOD - 1);
				answer = (1LL * answer *
						        lgput(itr.first, exp)) % MOD;
			}

			if (count[pos][itr.first] > 0) {
				mst[itr.first].erase(mst[itr.first].find(count[pos][itr.first]));
			}
			count[pos][itr.first] += itr.second;
			mst[itr.first].insert(count[pos][itr.first]);

			if ((int)mst[itr.first].size() == n) {
				answer = (1LL * answer * lgput(itr.first, *mst[itr.first].begin())) % MOD;
			}
		}

		cout << answer << "\n";
	}

    return 0;
}