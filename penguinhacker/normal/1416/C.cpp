#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#define debug(x) cerr << "[" << #x << "] = [" << x << "]\n"

template<class A, class B> ostream& operator<< (ostream& out, pair<A, B> p) {
	return out << '[' << p.first << ", " << p.second << ']';
}

template<class T> ostream& operator<< (ostream& out, vector<T>& v) {
	out << '[';
	for (int i = 0; i < v.size(); ++i) {
		if (i > 0) {
			out << ", ";
		}
		out << v[i];
	}
	return out << ']';
}





int n, x = 0;
ll ans = 0;
ll adds[35][2]; //how much we add if we have 0, 1

void rec(vector<pair<int, int>> a, int bit) {
	if (a.empty() || bit == -1) {
		return;
	}
	vector<pair<int, int>> ls, rs;
	for (pair<int, int> i : a) {
		if (i.first & (1 << bit)) {
			rs.push_back(i);
		}
		else {
			ls.push_back(i);
		}
	}
	if (bit == 0) {
		//debug(ls);
		//debug(rs);
	}
	ll tot = (ll)ls.size() * (ll)rs.size();
	ll cur = 0;
	for (int p1 = 0, p2 = 0; p1 < ls.size(); ++p1) {
		while(p2 < rs.size() && rs[p2].second < ls[p1].second) {
			++p2;
		}
		cur += p2;
	}
	assert(cur <= tot);
	adds[bit][0] += cur;
	adds[bit][1] += tot - cur;
	rec(ls, bit - 1);
	rec(rs, bit - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	rec(a, 30);
	for (int i = 0; i < 30; ++i) {
		ans += min(adds[i][0], adds[i][1]);
		/*if (i < 3) {
			cout << adds[i][0] << " " << adds[i][1] << "\n";
		}*/
		if (adds[i][0] > adds[i][1]) {
			x += 1 << i;
		}
	}
	cout << ans << " " << x;
	return 0;
}