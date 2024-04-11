#include <iostream>
#include <algorithm>
int n, t, tot[4] = {}, i, p[5001][4] = {};
int main() {
	using namespace std;
	cin >> n;
	for(i = 1; i <= n; i++) {
		cin >> t;
		p[++tot[t]][t] = i;
	}
	t = min(tot[1], min(tot[2], tot[3]));
	cout << t << endl;
	for(i = 1; i <= t; i++) {
		cout << p[i][1] << " " << p[i][2] << " " << p[i][3] << endl;
	}
	return 0;
}