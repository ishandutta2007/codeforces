/*
_NUUUUUUU_
*/

#include<iostream>
#include<algorithm>
#include<vector>;
#include<map>
#include<set>
#include<queue>

using namespace std;

#define ll long long

struct cmp {
	bool operator()(const pair < ll, ll > &p1, const pair < ll, ll > &p2) {
		if (p1.second == p2.second) {
			return p1.first < p2.first;
		}
		else {
			return p1.second < p2.second;
		}
	}
};
int main()
{
	ll n, k;
	cin >> n >> k;
	vector< ll > a(n + 1);
	vector< int > c(n + 1);
	set < pair < int, int > , cmp > s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		s.insert(make_pair(i, c[i]));
	}
	for (int i = 0; i < k; i++) {
		ll cnt = 0;
		ll num, q;
		cin >> num >> q;
		ll cn = min(q, a[num]);
		q -= cn;
		a[num] -= cn;
		cnt += cn * c[num];
		if (a[num] == 0) {
			s.erase(make_pair(num, c[num]));
		}
		while (q > 0 && s.size() > 0) {
			pair<int, int> now = *s.begin();
			s.erase(now);
			ll cn = min(a[now.first], q);
			cnt += cn * now.second;
			q -= cn;
			a[now.first] -= cn;
			if (a[now.first] > 0) {
				s.insert(now);
			}
		}
		if (q > 0) {
			cout << 0 << endl;
		}
		else {
			cout << cnt << endl;
		}
	}
}