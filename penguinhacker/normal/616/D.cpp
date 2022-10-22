#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, num=0, a[500000], cnt[1000001];
set<int> s;

int ret=0, lans, rans;
void add(int ind) {
	s.insert(a[ind]);
	if (cnt[a[ind]]==0) ++num;
	++cnt[a[ind]];
}
void remove(int ind) {
	if (cnt[a[ind]]==1) {
		--num;
		s.erase(a[ind]);
	}
	--cnt[a[ind]];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; ++i) cin >> a[i];
	for (int l=0, r=0; r<n; ++r) {
		add(r);
		while(num>k) {
			remove(l++);
		}
		if (r-l+1>ret) {
			ret=r-l+1;
			lans=l, rans=r;
		}
	}
	cout << lans+1 << ' ' << rans+1;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/