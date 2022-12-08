#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int N = 1e5 + 10;

int n;
long long a[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n == 1) {
		cout << 1 << " " << 1 << endl << -1 << endl;
		cout << 1 << " " << 1 << endl << 1 << endl;
		cout << 1 << " " << 1 << endl << -a[1] << endl;
		return 0;
	}
	cout << 1 << " " << n << endl;
	for (int i = 1; i <= n; i++) {
		long long t = (n - 1) - (a[i] % (n - 1) + (n - 1)) % (n - 1);
		cout << t * n << " ";
		a[i] += t * n;
	}
	cout << endl;
	cout << 1 << " " << 1 << endl << -a[1] << endl;
	cout << 2 << " " << n << endl;
	for (int i = 2; i <= n; i++)
		cout << -a[i] << " ";
	cout << endl;
	return 0;
}