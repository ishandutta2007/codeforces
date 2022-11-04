#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<string>
using namespace std;
int a[200001];
int b[200001];
int tp[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	const int beg = 100000;
	int t;
	cin >> t;
	for (int j = 0; j < t; ++j) {
		int n;
		cin >> n;
		int s = 0;
		for (int i = 0; i <= n; ++i)a[i + beg] = a[beg-i] = b[beg + i] = b[beg - i] = n + 1;
		a[beg] = b[beg] = n;
		for (int i = 1; i <= n; ++i) {
			int tmp;
			cin>>tmp;
			if (tmp == 1)++s;
			else --s;
			a[beg + s] = n - i;
		}
		for (int i = 1; i <= n; ++i) {
			cin >> tp[i];
		}
		s = 0;
		for (int i = n; i > 0; --i) {
			if (tp[i] == 1)++s;
			else --s;
			b[beg + s] = i - 1;
		}
		int res = 2 * n;
		for (int i = beg + n, i1 = beg - n; i >= beg - n; --i, ++i1) {
			if (b[i1] != n + 1 && a[i] != n + 1 && a[i] + b[i1] < res)res = a[i] + b[i1];
			
		}
		cout << res << endl;
	}
	return 0;
}