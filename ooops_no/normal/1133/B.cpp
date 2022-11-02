/*
_NUUUUUUU_
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
using namespace std;

#define int long long


#define pb push_back


signed main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	vector<int> v(b);
	for (int i = 0; i < a; i++) {
		int n;
		cin >> n;
		v[n%b]++;
	}
	int ans = 0;
	for (int i = 1; i < b; i++) {
		if (i == b - i) {
			ans += v[i] / 2 * 2;
			continue;
		}
		ans += min(v[i], v[b - i]);
	}
	cout << ans + v[0] / 2 * 2;
}