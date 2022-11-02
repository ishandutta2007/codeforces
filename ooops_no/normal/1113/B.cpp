#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	sort(v.begin(), v.end());
	ll mn = sum;
	for (int i = n - 1; i > -1; i--) {
		for (int j = 2; j <= sqrt(v[i]) + 1; j++) {
			if (v[i] % j == 0) {
				ll sm = sum;
				sm -= v[i] - v[i] / j;
				sm += v[0] * (j - 1);
				mn = min(mn, sm);
				sm = sum;
				int d = v[i] / j;
				sm -= v[i] - v[i] / d;
				sm += v[0] * (d - 1);
				mn = min(mn, sm);
			}
		}
		ll sm = sum;
		sm += v[0] * v[i];
		sm -= v[i];
		mn = min(mn, sm);
	}
	cout << mn;
}