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
	int n, k, cnt = 0, sm = 0;
	cin >> n >> k;
	vector<pair<int, int>> v(n);
	multiset<int> s;
	for (int i = 0; i < n; i++) {
		cin >> v[i].second >> v[i].first;
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		if (s.size() < k) {
			s.insert(v[i].second);
			cnt += v[i].second;
			sm = max(sm, v[i].first * cnt);
		}
		else {
			int f = *s.begin();
			cnt -= f;
			s.erase(s.find(f));
			cnt += v[i].second;
			s.insert(v[i].second);
			sm = max(sm, v[i].first * cnt);
		}
	}
	cout << sm;
}