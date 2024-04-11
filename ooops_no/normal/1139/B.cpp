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
#define mp make_pair


signed main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n, m = 0, s = 0;
	cin >> n;
	m = n;
	vector<int> v(n);
	while (n--) {
		cin >> v[n];
	}
	for (int i = 1; i < m; i++) {
		v[i] = max((int)0, min(v[i], v[i - 1] - 1));
	}
	for (auto to : v) {
		s += to;
	}
	cout << s;
}