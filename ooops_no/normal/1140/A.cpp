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
	int n, cnt = 0;
	cin >> n;
	vector<int> v(n);
	set<int> s;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		s.insert(a);
		s.erase(i + 1);
		if (s.empty()) {
			cnt++;
		}
	}
	cout << cnt;
}