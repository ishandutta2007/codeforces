#include <bits/stdc++.h>

/**
 * Author: Niyaz Nigmatullin
 */

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	set<int> q;
	set<int> w;
	int cl = 0;
	auto it = q.end();
	int after = 0;
	long long sumAll = 0;
	long long sumAfter = 0;
	for (int i = 0; i < n; i++) {
		int tp, d;
		cin >> tp >> d;
		if (d > 0) {
			if (it != q.end() && d > *it) {
				sumAfter += d;
				++after;
			}
			q.insert(d);
			if (tp > 0) {
				cl++;
				w.insert(d);
			}
			sumAll += d;
		} else {
			d = -d;
			if (q.find(d) == it) {
				it = q.erase(it);
				--after;
				sumAfter -= d;
			} else {
				if (it != q.end() && d > *it) {
					--after;
					sumAfter -= d;
				}
				q.erase(q.find(d));
			}
			if (tp > 0) {
				--cl;
				w.erase(w.find(d));
			}
			sumAll -= d;
		}
		// cout << sumAll << ' ' << after << ' ' << sumAfter << endl;
		while (after < cl) {
			--it;
			after++;
			sumAfter += *it;			
		}
		while (after > cl) {
			sumAfter -= *it;
			++it;
			after--;
		}
		long long currentAns = sumAll + sumAfter;
		if (*w.begin() >= *it) {
			currentAns -= *w.begin();
			if (it != q.begin()) {
				auto it2 = it;
				--it2;
				currentAns += *it2;
			}
		}
		cout << currentAns << '\n';
	}
}