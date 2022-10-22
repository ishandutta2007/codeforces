#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, q, a[mxN];
set<ar<int, 2>> st;

set<ar<int, 2>>::iterator ins(ar<int, 2> x) {
	auto it=st.insert(x).first;
	if (it!=st.begin()&&(*prev(it))[1]==x[1]) {
		--it;
		st.erase(next(it));
	}
	if (next(it)!=st.end()&&(*next(it))[1]==x[1])
		st.erase(next(it));
	return it;
}

void upd(int i, int t) { // from a run of t's and find first t^1
	auto it=--st.upper_bound({i, 69});
	int change=i;
	if ((*it)[1]==t) {
		change=(*next(it))[0];
		if ((*it)[0]==i)
			st.erase(it);
		it=ins({i, t^1});
	}
	if (change==(*it)[0]&&next(it)!=st.end()&&(*next(it))[0]==change+1) {
		st.erase(it);
		ins({change, t});
	} else if (change==(*it)[0]) {
		st.erase(it);
		st.insert({change+1, t^1});
	} else {
		if (next(it)==st.end()||(*next(it))[0]>change+1)
			st.insert({change+1, t^1});
		ins({change, t});
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	st.insert({0, 0});
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		upd(a[i], 1);
	}
	while(q--) {
		int i, x;
		cin >> i >> x, --i;
		upd(a[i], 0);
		upd(a[i]=x, 1);
		cout << (*st.rbegin())[0]-1 << "\n";
	}
	return 0;
}