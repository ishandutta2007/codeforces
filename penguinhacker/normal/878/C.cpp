#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k;

struct Group {
	int sz=1;
	vector<int> lo, hi;
	Group() {
		lo.resize(k), hi.resize(k);
		for (int i=0; i<k; ++i)
			cin >> lo[i], hi[i]=lo[i];
	}
	void merge(const Group& o) {
		sz+=o.sz;
		for (int i=0; i<k; ++i) {
			lo[i]=min(lo[i], o.lo[i]);
			hi[i]=max(hi[i], o.hi[i]);
		}
	}
	bool operator<(const Group& o) const {
		for (int i=0; i<k; ++i)
			if (hi[i]>=o.lo[i])
				return 0;
		return 1;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	set<Group> s;
	for (int i=0; i<n; ++i) {
		Group g;
		auto it=s.lower_bound(g);
		while(it!=s.end()&&!(g<*it)) {
			g.merge(*it);
			s.erase(it);
			it=s.lower_bound(g);
		}
		s.insert(g);
		cout << s.rbegin()->sz << "\n";
	}
	return 0;
}