#include <bits/stdc++.h>
#define pb push_back
#define mop make_pair
#define fi first
#define int long long
#define se second
#ifndef print
#define print(...)
#endif
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int n[20];
int v[20][5006];
std::map<int, pair<int, int>> mpp;
int ss[20];
std::map<int, int> mp;
int su;

int rem(int i, int val) {
	return (su - ss[i]) + val;
}

inline int fin(int val) {
	if (mp.find(val) == mp.end()) return -1;
	return mp[val];
}

void ins(int mask, int in, int i) {
	mpp[mask] = {in, i};
}

pair<int, int> ans[1000000];
int k;
pair<int, int> pp[20];

void ssolve(int mask1) {
	// print(mask1);
	auto po = mpp[mask1];
	// print(po);
	int in = po.fi;
	int i = po.se;
	int mask = (1 << in);
	int la = rem(in, v[in][i]);
	int ii = fin(la);
	int i2 = in;
	// print(v[in][i], in, ss[in], la);
	while (ii != -1) {
		// print(ii, mask, la);
		if (ii == in && la == v[in][i]) {
			// ins(mask, in, i);
			pp[ii] = {la, i2};
			// print(ii, la, i2);
			break;
		} else if ((1 << ii) & mask) {
			break;
		} else {
			pp[ii] = {la, i2};
			mask |= (1 << ii);
			la = rem(ii, la);
		}
		i2 = ii;
		ii = fin(la);
	}
}

void solve(int mask) {
	// print(mask);
	if (ans[mask] == mop(-1ll, -1ll)) {
		ssolve(mask);
		return;
	}
	solve(ans[mask].fi);
	solve(ans[mask].se);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> n[i];
		for (int j = 0; j < n[i]; ++j) {
			cin >> v[i][j];
			ss[i] += v[i][j];
			mp[v[i][j]] = i;
		}
		su += ss[i];
	}
	if (su % k != 0) {
		cout << "No";
		return 0;
	}
	su /= k;
	// print(su);
	for (int in = 0; in < (k); ++in) {
		// if (ss[in] == su) {
		// 	ins(1 );
		// } 
		for (int i = 0; i < n[in]; ++i) {
			int mask = (1 << in);
			int la = rem(in, v[in][i]);
			int ii = fin(la);
			while (ii != -1) {
				if (ii == in && la == v[in][i]) {
					ins(mask, in, i);
					break;
				} else if ((1 << ii) & mask) {
					break;
				} else {
					mask |= (1 << ii);
					la = rem(ii, la);
				}
				ii = fin(la);
			}
		}
	}
	// print(mpp);
	for (auto ma : mpp) {
		ans[ma.fi] = {-1, -1};
	}
	for (int mask = 1; mask < (1 << k); ++mask) {
		if (ans[mask] == mop(0ll, 0ll)) {
			for (int submask = mask; submask > 0; submask = (submask - 1) & (mask)) {
				if (ans[submask] != mop(0ll, 0ll) && ans[mask ^ (submask)] != mop(0ll, 0ll)) {
					ans[mask] = {submask, mask ^ submask};
					break;
				}
			}
		}
	}
	if (ans[(1 << k) - 1] != mop(0ll, 0ll)) {
		// print(ans[(1 << k) - 1]);
		cout << "Yes\n";
		solve((1 << k) - 1);
		for (int i = 0; i < k; ++i) {
			cout << pp[i].fi << " " << pp[i].se + 1 << "\n";
		}
	} else {
		cout << "No";
	}
}