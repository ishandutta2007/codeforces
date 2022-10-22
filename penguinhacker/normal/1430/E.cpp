#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 200000;
template<class T, int SZ> struct BIT { //try to always use long long
	const static int n = SZ + 1;
	T bit[n];
	BIT() {memset(bit, 0, sizeof(bit));}
	void upd(int i, T val) {for (++i; i<n; i+=i&-i) bit[i]+=val;}
	void upd(int l, int r, T val) {
		upd(l, val);
		upd(r + 1, -val);
	}
	T qry(int i) {T res=0; for (++i; i>0; i-=i&-i) res+=bit[i]; return res;}
};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	string s2 = s;
	reverse(s2.begin(), s2.end());
	deque<int> oc[26];
	for (int i = 0; i < n; ++i) {
		oc[s[i] - 'a'].push_back(i);
	}
	ll ans = 0;
	BIT<ll, mxN> bit;
	for (int i = 0; i < n; ++i) {
		bit.upd(i, i, i);
	}
	for (int i = 0; i < n; ++i) {
		int c = s2[i] - 'a';
		assert(!oc[c].empty());
		int pos = oc[c][0];
		ans += bit.qry(pos);
		bit.upd(pos + 1, n - 1, -1);
		oc[c].pop_front();
	}
	cout << ans;
	return 0;
}