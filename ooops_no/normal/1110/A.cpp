#include<vector>
#include<iostream>
#include<algorithm>

#define ll long long

using namespace std;


int main() {
	int n, b, k = 0, k1 = 0;
	cin >> b >> n;
	int a;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	ll sum = 0;
	int x = 1;
	reverse(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		sum += v[i] * x;
		x *= b;
	}
	if (sum % 2 == 0) {
		cout << "even";
	}
	else {
		cout << "odd";
	}
}