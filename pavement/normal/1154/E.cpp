#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, K, a[200005], p[200005], c;
bool f;
set<int> s;
bitset<200005> o;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		s.insert(i);
		p[a[i]] = i;
	}
	for (c = N; !s.empty(); f = !f) {
		while (c >= 1) {
			auto it = s.lower_bound(p[c]);
			if (it == s.end() || *it > p[c]) c--;
			else break;
		}
		vector<set<int>::iterator> v;
		auto it = s.lower_bound(p[c]), it2 = it;
		v.push_back(it);
		for (int i = 0; i < K; i++) {
			if (++it == s.end()) break;
			v.push_back(it);
		}
		for (int i = 0; i < K; i++) {
			if (it2 == s.begin()) break;
			v.push_back(--it2);
		}
		for (auto i : v)
			o[*i] = f, s.erase(i);
	}
	for (int i = 0; i < N; i++) cout << o[i] + 1;
	cout << '\n';
}