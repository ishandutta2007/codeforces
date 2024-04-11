#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	
	
	cin.sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	string s[n];
	int idx[n];
	for (int i = 0; i < n; ++i) {
		idx[i] = i;
		cin >> s[i];
	}

	sort(idx, idx+n, [n, &s] (int a, int b) {
	    while (a < n && b < n && s[a] == s[b]) { ++a; ++b; }
	    if (a < n && b < n) return s[a] < s[b];
	    return a > b;
	});

	int lcp[n-1];
	for (int i = 0; i < n-1; ++i) {
		int &x = lcp[i];
		const int id1 = idx[i], id2 = idx[i+1];
		for (x = 0; id1 + x < n && id2 + x < n && s[id1 + x] == s[id2 + x]; ++x); 
	}
	
	int total = n-1;
	for (int i = 0; i < n; ++i) {
		total += s[i].size();
	}

	int ans = 0;
	for (int i = 0; i < n-1; ++i) {
		int len = 0;
		for (int j = 1; j <= lcp[i]; ++j) {
			len += s[idx[i] + j-1].length();

			int l = i, h = i;
			while (l > 0 && lcp[l-1] >= j) --l;
			while (h+1 < n && lcp[h] >= j) ++h;

			set<int> id (idx + l, idx + h + 1);
			int total = 0, last = 0;
			for (int x : id) {
				if (x >= last) {
					++total;
					last = x + j;
				}
			}
			if (total > 1)
			ans = max(ans, total * (len-1));
		}
	}

	cout << (total - ans) << endl;

	return 0;
}