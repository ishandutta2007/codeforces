#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

ll a, b, c, cnt=0;
vector<int> num;

ll binPow(ll b, int pow) {
	ll res=1;
	while (pow>0) {
		if (pow&1)
			res *= b;
		b *= b;
		pow >>= 1;
	}
	return res;
}

int sumDigits(int x) {
	int sum = 0;
	while (x>0) {
		sum += x%10;
		x /= 10;
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c;
	for (int i=1; i<=81; ++i) {
		ll x = b*binPow(i,a)+c;
		if (0<x && x<1e9 && sumDigits(x)==i) {
			cnt++;
			num.push_back(x);
		}
	}
	cout << cnt << '\n';
	for (int i:num)
		cout << i << ' ';
	return 0;
}