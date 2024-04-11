#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6, INF=1e9;
int n, a[mxN];
ll ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	deque<ar<int, 2>> st;
	for (int i=0; i<2*n; ++i) {
		int x=a[i%n];
		if (i>=n) {
			if (st[0][1]==i-n)
				st.pop_front();
			int p=lower_bound(st.begin(), st.end(), ar<int, 2>{x, INF}, greater<>())-st.begin();
			p=max(0, p-1);
			ans+=st.size()-p;
		}
		while(st.size()&&x>st.back()[0])
			st.pop_back();
		st.push_back({x, i});
	}
	sort(a, a+n, greater<>());
	int x=count(a, a+n, a[0]);
	int y=count(a, a+n, a[1]);
	if (a[0]==a[1])
		ans-=(ll)x*(x-1)/2;
	else
		ans-=y;
	cout << ans;
	return 0;
}