#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m[1000], bestInd=0;
ll best=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> m[i];

	for (int peak=0, mn; peak<n; ++peak) {
		ll current=m[peak];
		mn = m[peak];
		for (int i=peak-1; i>=0; --i) {
			mn = min(mn, m[i]);
			current += mn;
		}
		mn = m[peak];
		for (int i=peak+1; i<n; ++i) {
			mn = min(mn, m[i]);
			current += mn;
		}
		if (current > best) {
			best = current;
			bestInd = peak;
		}
	}
	
	for (int i=bestInd-1; i>=0; --i)
		m[i] = min(m[i], m[i+1]);
	for (int i=bestInd+1; i<n; ++i)
		m[i] = min(m[i], m[i-1]);
	
	for (int i=0; i<n; ++i) {
		cout << m[i] << ' ';
	}
    return 0;
}