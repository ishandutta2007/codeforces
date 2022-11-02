#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <intrin.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n), howmany(n, 0);
	foru(i, 0, n)cin >> a[i];
	int iter = 0;
	ll steps = 0;
	while (iter < n) {
		if (a[iter] == 1) {
			if (iter != n - 1)howmany[iter + 1] += howmany[iter];
			iter++;
		}
		else {
			int goal = n - iter;
			if (a[iter] > goal) {
				int rem = (a[iter] - goal);
				if (rem > howmany[iter]) {
					rem -= howmany[iter];
					howmany[iter] = 0;
					steps += rem;
					a[iter] = goal;
				}
				else {
					howmany[iter] -= rem;
					a[iter] = goal;
				}
			}
			else {
				while (a[iter] > 1) {
					if (iter + a[iter] < n)howmany[iter + a[iter]]++;
					a[iter]--;
					if (howmany[iter] == 0)
						steps++;
					else
						howmany[iter]--;
				}
			}
		}
	}
	cout << steps << '\n';
}


int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}