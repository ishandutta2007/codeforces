#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	if (b<a)
		swap(a, b);
	if (b>=2*a) {
		cout << a;
		return 0;
	}
	int dif=b-a;
	a -= dif; b -= 2*dif;
	cout << dif + (a+b)/3;
	return 0;
}