#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000;
ll n, ans;
bool b;
int main() {
	cin >> n;
	while (n) {
		ans += n % 10;
		if (n % 10 != 9) b = 1;
		if (b) {
			ans += 9;	
		}
		n /= 10;
	}
	cout << ans - (b * 9);
}