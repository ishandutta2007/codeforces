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
#include<deque>
using namespace std;

#define int long long
#define pb push_back
#define ld long double


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
	for (int i = 0; i < n; i++) {
		v.pb(v[i]);
	}
	int last = 0, mx = 0, cnt = 0;
	for (int i = 0; i < n * 2; i++) {
		if (v[i] == 1) {
			cnt++;
		}
		else {
			mx = max(mx, cnt);
			cnt = 0;
		}
	}
	cout << max(mx, cnt);
}