#include <iostream>

using namespace std;

typedef long long ll;

ll a, b, c;

int main() {
	cin >> a >> b >> c;
	ll s1 = 2*c+min(a,b)*2;
	if (a > b) s1++;
	ll s2 = 0;
	if (b > 0) {
		s2++;
		b--;
		s2 += 2*c;
		s2 += min(a,b)*2;
		if (a > b) s2++;
	}
	cout << max(s1,s2) << "\n";
}