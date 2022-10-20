#include <bits/stdc++.h>

using namespace std;

long long val;
long long m, n;

int main() {
	cin >> n >> m;
	long long res;
	long long foo = 1;
	for (int i = 1; i <= n && foo <= m; i++) {
		foo *= 2;
	}
	//cout << m << " " << foo << endl;
	cout << m % foo << endl;
	return 0;
}