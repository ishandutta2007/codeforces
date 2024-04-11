#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, ans;
vector<int> occ[200], v;

void calc() {
	int x=0, s=0, l=0, r=v.size()-1;
	for (int i : v)
		s+=i;
	while(1) {
		++x;
		bool bl=0, br=0;
		while(l<=r&&!bl) {
			if (v[l]==0)
				bl=1;
			else
				--s;
			++l;
		}
		while(l<=r&&!br) {
			if (v[r]==0)
				br=1;
			else
				--s;
			--r;
		}
		if (l>r)
			break;
		ans=max(ans, 2*x+s);
	}
}

void solve() {
	cin >> n;
	for (int i=0; i<200; ++i)
		occ[i].clear();
	for (int i=0, a; i<n; ++i) {
		cin >> a;
		occ[a-1].push_back(i);
	}
	for (int i=0; i<200; ++i)
		occ[i].push_back(n);
	ans=1;
	for (int i=0; i<200; ++i) {
		for (int j=0; j<200; ++j) {
			if (occ[i].size()==1||occ[j].size()==1)
				continue;
			if (i==j) {
				ans=max(ans, (int)occ[i].size()-1);
				continue;
			}
			for (int a=0, b=0; a<occ[i].size()-1||b<occ[j].size()-1;) {
				if (occ[i][a]<occ[j][b]) {
					v.push_back(0);
					++a;
				}
				else {
					v.push_back(1);
					++b;
				}
			}
			calc();
			v.clear();
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}