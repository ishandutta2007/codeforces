#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int n, t, r, a[300], ans=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> t >> r;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	if (t<r) {
		cout << -1;
		return 0;
	}
	queue<int> q;
	for (int i=0; i<n; ++i) {
		while (!q.empty()&&q.front()<=a[i])
			q.pop();
		int x=r-q.size();
		ans+=x;
		for (int j=a[i]+t-x+1; j<=a[i]+t; ++j)
			q.push(j);
	}
	cout << ans;
	return 0;
}