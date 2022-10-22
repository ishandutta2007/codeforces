#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
string s;

void test_case() {
	cin >> n >> s;
	map<int, int> oc;
	oc[0]++;
	int cur=0;
	ll ans=0;
	for (char c: s) {
		int x=c-'0'-1;
		cur+=x;
		ans+=oc[cur]++;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		test_case();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/