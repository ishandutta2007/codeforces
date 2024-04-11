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
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int mx = 1;
	for (int i = 0; i < n; i++) {
		int j;
		for (j = i + mx; j < n; j++) {
			if (v[j] - v[i] > 5) {
				break;
			}
		}
		mx = max(mx, j - i);
	}
	cout << mx;
}