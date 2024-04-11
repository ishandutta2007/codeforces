#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, x, y, d;
void test_case() {
	cin >> n >> x >> y;
	for (d=1; d<=y-x; ++d)
		if ((y-x)%d==0&&(y-x)/d+1<=n) break;
	vector<int> ans;
	for (int i=x; i<=y; i+=d) ans.push_back(i);
	for (int i=x-d; i>0&&ans.size()<n; i-=d) ans.push_back(i);
	for (int i=y+d; ans.size()<n; i+=d) ans.push_back(i);
	//sort(ans.begin(), ans.end());
	for (int i: ans) cout << i << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1; cin >> t;
	while(t--) test_case();
	return 0;
}