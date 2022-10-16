#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	int a, b, c;
	cout << "? 1 2" << endl;
	cin >> a;
	cout << "? 2 3" << endl;
	cin >> b;
	cout << "? 3 1" << endl;
	cin >> c;
	int tot = (a+b+c)/2;
	vector<int> ans(n+1);
	ans[1] = tot - b;
	ans[2] = tot - c;
	ans[3] = tot - a;
	for (int i = 4; i <= n; i++) {
	      cout << "? 1 " << i << endl;
	      cin >> a;
	      ans[i] = a - ans[1];
	}
	cout << "! ";
	for (int i = 1; i <= n; i++) {
	      cout << ans[i] << " ";
	}
	cout << endl;
	
	return 0;
}