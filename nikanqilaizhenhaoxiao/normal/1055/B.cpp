#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, m, l;
	cin >> n >> m >> l;
	vector<long long> a(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	set<pair<int, int> > s;
	for (int i = 1; i <= n; ++i) if(a[i] > l) {
		int j = i;
		while(j + 1 <= n && a[j + 1] > l) ++j;
		s.insert(make_pair(i, j));
		i = j;
	}
	while(m--) {
		int t;
		cin >> t;
		if(!t) { cout << s.size() << endl; continue; }
		int i, x;
		cin >> i >> x;
		if(a[i] <= l && a[i] + x > l) {
			s.insert(make_pair(i, i));
			auto it = s.lower_bound(make_pair(i, i)), p = s.begin();
			p = it; ++p;
			if(p != s.end()) {
				if(p->first == i + 1) {
					int r = p->second;
					s.erase(it);
					s.erase(p);
					s.insert(make_pair(i, r));
				}
			}
			it = s.lower_bound(make_pair(i, i));
			if(it != s.begin()) {
				p = it;
				--p;
				if(p->second == i - 1) {
					int l = p->first, r = it->second;
					s.erase(it);
					s.erase(p);
					s.insert(make_pair(l, r));
				}
			}
		}
		a[i] += x;
	}
	return 0;
}