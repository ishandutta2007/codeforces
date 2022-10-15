#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<int> zz, aa, bb;

void rip() {
	cout << "-1\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int t, a, b;
		cin >> t >> a >> b;
		if (a && b) zz.push_back(t);
		else if (a) aa.push_back(t);
		else if (b) bb.push_back(t);
	}
	sort(zz.rbegin(),zz.rend());
	sort(aa.rbegin(),aa.rend());
	sort(bb.rbegin(),bb.rend());
	int ak = 0, bk = 0;
	ll r = 0;
	while (true) {
		if (ak >= k && bk >= k) break;
		if (ak < k && bk < k) {
			if (zz.size() && aa.size() && bb.size()) {
				if (zz.back() <= aa.back()+bb.back()) {
					r += zz.back();
					zz.pop_back();
					ak++; bk++;
				} else {
					r += aa.back()+bb.back();
					aa.pop_back();
					bb.pop_back();
					ak++; bk++;
				}
			} else if (zz.size()) {
				r += zz.back();
				zz.pop_back();
				ak++; bk++;
			} else if (aa.size() && bb.size()) {
				r += aa.back()+bb.back();
				aa.pop_back();
				bb.pop_back();
				ak++; bk++;
			} else rip();
		} else if (ak < k) {
			if (zz.size() && aa.size()) {
				if (zz.back() < aa.back()) {
					r += zz.back();
					zz.pop_back();
					ak++;
				} else {
					r += aa.back();
					aa.pop_back();
					ak++;
				}
			} else if (zz.size()) {
				r += zz.back();
				zz.pop_back();
				ak++;
			} else if (aa.size()) {
				r += aa.back();
				aa.pop_back();
				ak++;
			} else rip();
		} else if (bk < k) {
			if (zz.size() && bb.size()) {
				if (zz.back() < bb.back()) {
					r += zz.back();
					zz.pop_back();
					bk++;
				} else {
					r += bb.back();
					bb.pop_back();
					bk++;
				}
			} else if (zz.size()) {
				r += zz.back();
				zz.pop_back();
				bk++;
			} else if (bb.size()) {
				r += bb.back();
				bb.pop_back();
				bk++;
			} else rip();
		}
	}
	cout << r << "\n";
}