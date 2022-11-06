#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, M;
set<pair<int, int> > cnt;
map<int, int> tmp;
stack<pair<int, int> > rem;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1, A; i <= N; i++) {
		cin >> A;
		tmp[A]++;
	}
	for (auto i : tmp)
		cnt.emplace(i.second, i.first);
	for (int i = 1; i <= N; i++) {
		int t = 0;
		for (int k = i; k <= N; k <<= 1) {
			auto it = cnt.lower_bound(make_pair(k, -1));
			if (it == cnt.end()) break;
			else t += k, rem.push(*it), cnt.erase(it);
		}
		for (; !rem.empty(); rem.pop())
			cnt.insert(rem.top());
		M = max(M, t);
	}
	cout << M << '\n';
}