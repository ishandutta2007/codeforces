#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n + 5];
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	cout << a[2] - a[1] << ' ' << a[n] - a[1] << '\n';
	for(int i = 2; i < n; i++)
		cout << min(a[i] - a[i - 1], a[i + 1] - a[i]) << ' ' << max(a[i] - a[1], a[n] - a[i]) << '\n';
	cout << a[n] - a[n - 1] << ' ' << a[n] - a[1] << '\n';
	return 0;
}