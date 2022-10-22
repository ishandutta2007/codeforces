#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n, m, ans[mxN];
char s[mxN];
ar<int, 2> a[mxN];

void solve(vector<int>& v) {
	vector<int> l, r;
	for (int i : v) {
		if (s[a[i][1]]=='R') {
			r.push_back(i);
		} else {
			if (r.size()) {
				int j=r.back();
				r.pop_back();
				ans[a[i][1]]=ans[a[j][1]]=(a[i][0]-a[j][0])/2;
			} else {
				l.push_back(i);
			}
		}
	}
	reverse(l.begin(), l.end());
	while(l.size()>=2) {
		int i=l.back();
		l.pop_back();
		int j=l.back();
		l.pop_back();
		ans[a[i][1]]=ans[a[j][1]]=(a[i][0]+a[j][0])/2;
	}
	while(r.size()>=2) {
		int i=r.back();
		r.pop_back();
		int j=r.back();
		r.pop_back();
		ans[a[i][1]]=ans[a[j][1]]=(m-a[i][0]+m-a[j][0])/2;
	}
	if (l.size()&&r.size()) {
		int i=l[0], j=r[0];
		int d=a[i][0]+m-a[j][0]+m;
		if (d%2==0) {
			ans[a[i][1]]=ans[a[j][1]]=d/2;
		}
	}
}

void solve() {
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> a[i][0], a[i][1]=i;
	for (int i=0; i<n; ++i)
		cin >> s[i];
	sort(a, a+n);
	vector<int> oc[2];
	for (int i=0; i<n; ++i)
		oc[a[i][0]%2].push_back(i);
	memset(ans, -1, 4*n);
	solve(oc[0]);
	solve(oc[1]);
	for (int i=0; i<n; ++i)
		cout << ans[i] << " ";
	cout << "\n";
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