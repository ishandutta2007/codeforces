#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, k;
vector<pair<int, string>> ans;

void printAns() {
	cout << "YES\n" << ans.size() << '\n';
	for (auto x : ans)
		cout << x.first << ' ' << x.second << '\n';
	exit(0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	if (4*n*m-2*n-2*m<k) {
		cout << "NO";
		return 0;
	}
	if (k<=m-1) {
		ans.emplace_back(k, "R");
		printAns();
	}
	if (m>1)
		ans.emplace_back(m-1, "R");
	k-=m-1;
	if (k<=m-1) {
		ans.emplace_back(k, "L");
		printAns();
	}
	k-=m-1;
	if (m>1)
		ans.emplace_back(m-1, "L");

	int cnt=0;
	while(cnt<n-1&&k>=1+4*(m-1)) {
		ans.emplace_back(1, "D");
		if (m>1) {
			ans.emplace_back(m-1, "R");
			ans.emplace_back(m-1, "UDL");
		}
		k-=1+4*(m-1);
		++cnt;
	}
	if (k==0)
		printAns();
	if (cnt<n-1) {
		ans.emplace_back(1, "D");
		--k;
		if (k==0)
			printAns();
		if (k<=m-1) {
			ans.emplace_back(k, "R");
			printAns();
		}
		ans.emplace_back(m-1, "R");
		k-=m-1;
		if (k>=3) {
			ans.emplace_back(k/3, "UDL");
			k-=k/3*3;
		}
		if (k==1)
			ans.emplace_back(1, "U");
		else if (k==2)
			ans.emplace_back(1, "UD");
	}
	else {
		if (k)
			ans.emplace_back(k, "U");
	}
	printAns();
}