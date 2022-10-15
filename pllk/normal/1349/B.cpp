#include <iostream>

using namespace std;

int n, k;
int a[101010];

void lol() {
	cin >> n >> k;
	int c = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k) a[i] = 0;
		else if (a[i] < k) a[i] = -1;
		else a[i] = 1;
		if (a[i] == 0) c++;
	}
	int ok = 0;
	if (n == 1 && a[1] == 0) ok = 1;
	for (int i = 1; i <= n-1; i++) {
		if (a[i] >= 0 && a[i+1] >= 0) ok = 1;
	}
	for (int i = 1; i <= n-2; i++) {
		if (a[i] >= 0 && a[i+2] >= 0) ok = 1;
	}
	if (ok && c) cout << "yes\n";
	else cout << "no\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) lol();
}