#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
#include<deque>
#include<math.h>

using namespace std;

#define int long long
#define pb push_back
#define ld long double
#define mp make_pair

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		gcd(b, a % b);
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n, m, last, one;
	cin >> n >> m >> last;
	one = last;
	vector<int> v;
	map<int, int> u, u1;
	for (int i = 1; i < n; i++) {
		int a;
		cin >> a;
		v.pb(a - last);
		last = a;
	}
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		u[a] = 1;
		u1[a] = i + 1;
	}
	int g = v[0];
	for (int i = 1; i < n - 1; i++) {
		g = gcd(g, v[i]);
	}
	for (auto to : u) {
		int i = to.first;
		if (g % i == 0) {
			if (u[i]) {
				cout << "YES" << endl << one << " " << u1[i];
				return 0;
			}
			if (u[g / i]) {
				cout << "YES" << endl << one << " " << u1[g / i];
				return 0;
			}
		}
	}
	if (u[g]) {
		cout << "YES" << endl << one << " " << u1[g];
		return 0;
	}
	cout << "NO";
}