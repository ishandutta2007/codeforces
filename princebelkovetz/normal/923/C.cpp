#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int mod = 1e9 + 7;
struct node {
	int to[2] = { 0, 0 }, cnt[2] = { 0, 0 };
};
vector <node> bor(1);
const int bb = 31;
void push(int x) {
	int cur = 0;
	for (int i = bb; i >= 0; --i) {
		int bit = x >> i;
		bit = bit & 1;
		bor[cur].cnt[bit]++;
		if (bor[cur].to[bit]) {
			cur = bor[cur].to[bit];
		}
		else {
			bor[cur].to[bit] = bor.size();
			cur = bor.size();
			bor.push_back({});
		}
	}
}
int get(int x) {
	int cur = 0;
	int ans = 0;
	for (int i = bb; i >= 0; --i) {
		int bit = x >> i;
		bit = bit & 1;
		if (bor[cur].cnt[bit]) {
			bor[cur].cnt[bit]--;
			cur = bor[cur].to[bit];
		}
		else {
			ans += pow(2, i);
			assert(bor[cur].cnt[1 - bit]);
			bor[cur].cnt[1 - bit]--;
			cur = bor[cur].to[1 - bit];
		}
	}
	return ans;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(7);
	int n; cin >> n;
	vector <int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;
	for (auto x : b)
		push(x);
	for (int i = 0; i < n; ++i)
		cout << get(a[i]) << ' ';
}