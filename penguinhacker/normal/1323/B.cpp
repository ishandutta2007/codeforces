#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m, k, a[40000], b[40000];
vector<int> v1, v2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	int curr = 0;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		if (a[i])
			curr++;
		else {
			if (curr)
				v1.push_back(curr);
			curr = 0;
		}
	}
	if (curr)
		v1.push_back(curr);
	curr = 0;
	for (int i=0; i<m; ++i) {
		cin >> b[i];
		if (b[i])
			curr++;
		else {
			if (curr)
				v2.push_back(curr);
			curr = 0;
		}
	}
	if (curr)
		v2.push_back(curr);
	sort(v1.rbegin(), v1.rend());
	sort(v2.rbegin(), v2.rend());

	ll ans = 0;
	for (int i=0; i<n; ++i) {
		if (k%(i+1)==0&&k/(i+1)<=m) {
			int height = i+1;
			int width = k/height;
			while (!v1.empty()&&v1.back()<height)
				v1.pop_back();
			if (v1.empty())
				break;
			int x=0, y=0;
			for (int i : v1)
				x += i-height+1;
			for (int i : v2)
				y += max(0, i-width+1);
			ans += 1ll*x*y;
		}
	}
	cout << ans;
	return 0;
}