#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=500000;
int n, a[mxN], ans[mxN];
ll pre[mxN], suf[mxN];

ll sum=0;
stack<pair<ll, int>> s; // <num, occ>

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i], ans[i]=a[i];

	auto add=[](pair<ll, int> &cur) {
		s.push(cur);
		sum+=cur.first*cur.second;
	};
	auto remove=[](pair<ll, int> &cur) {
		assert(s.size()&&cur.first<=s.top().first);
		cur.second+=s.top().second;
		sum-=s.top().first*s.top().second;
		s.pop();
	};
	for (int i=0; i<n; ++i) {
		pair<ll, int> cur={a[i], 1};
		while(s.size()&&cur.first<=s.top().first) remove(cur);
		add(cur); pre[i]=sum;
	}
	while(s.size()) s.pop();
	sum=0;
	for (int i=n-1; ~i; --i) {
		pair<ll, int> cur={a[i], 1};
		while(s.size()&&cur.first<=s.top().first) remove(cur);
		add(cur); suf[i]=sum;
	}
	int ind=-1;
	for (int i=0; i<n; ++i)
		if (ind==-1||pre[i]+suf[i]-a[i]>=pre[ind]+suf[ind]-a[ind])
			ind=i;
	assert(ind!=-1);
	for (int i=ind-1; ~i; --i)
		ans[i]=min(ans[i], ans[i+1]);
	for (int i=ind+1; i<n; ++i)
		ans[i]=min(ans[i], ans[i-1]);
	for (int i=0; i<n; ++i)
		cout << ans[i] << ' ';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/