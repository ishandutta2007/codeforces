#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m, a[mxN], last[mxN][2];
set<ar<int, 2>> ls, rs; // possibilites on left side and right side

void reduce(set<ar<int, 2>>& s, int l, int r) {
	while(s.size()&&(*s.begin())[0]<l)
		s.erase(s.begin());
	while(s.size()&&(*s.rbegin())[0]>r)
		s.erase(--s.end());
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	memset(last, -1, sizeof(last));
	ls.insert({0, -1});
	rs.insert({0, -1});
	for (int i=0; i<n; ++i) {
		int l1, r1, l2, r2;
		cin >> a[i] >> l1 >> r1 >> l2 >> r2;
		bool rl=0, lr=0;
		if (i&&l1<=a[i]&&a[i]<=r1&&l2<=a[i-1]&&a[i-1]<=r2&&ls.size()) // right->left
			last[i][0]=i-1, rl=1;
		if (i&&l2<=a[i]&&a[i]<=r2&&l1<=a[i-1]&&a[i-1]<=r1&&rs.size()) // left->right
			last[i][1]=i-1, lr=1;
		if (l1<=a[i]&&a[i]<=r1) {
			reduce(rs, l2, r2);
			if (rl)
				rs.insert({a[i-1], i-1});
			else if (rs.size())
				last[i][0]=(*rs.begin())[1];
		} else
			rs.clear();
		if (l2<=a[i]&&a[i]<=r2) {
			reduce(ls, l1, r1);
			if (lr)
				ls.insert({a[i-1], i-1});
			else if (ls.size())
				last[i][1]=(*ls.begin())[1];
		} else
			ls.clear();
	}
	for (int p : {0, 1}) {
		if (last[n-1][p]!=-1) {
			cout << "Yes\n";
			vector<bool> ans(n);
			for (int i=n-1; ~i; i=last[i][p], p^=1)
				for (int j=last[i][p]+1; j<=i; ++j)
					ans[j]=p;
			for (bool i : ans)
				cout << i << " ";
			return 0;
		}
	}
	cout << "No";
	return 0;
}