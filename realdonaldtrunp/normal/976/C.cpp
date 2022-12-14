#include "bits/stdc++.h"
using namespace std;


map<int, set<pair<int,int> > > star;
int n;
set<pair<int,int> > s;
set<int> look;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		star[l].insert(make_pair(-r,i+1) );
		look.insert(l);
	}
	for (auto i : look) {
		for (auto it : star[i]) {
			int rig = -it.first;
			int id = it.second;
			auto f = s.lower_bound(make_pair(rig, -1));
			if (f != s.end()) {
				printf("%d %d\n", id,(*f).second);
				return 0;
			}
			s.insert(make_pair(rig,id));
		}
	}
	puts("-1 -1");
	return 0;
}