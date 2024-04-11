#include <iostream>

using namespace std;

long long ans = 0, n;

int main() {
	cin >> n;
	for(int i = 1;;i++) {
		if((n-2*i)%3) {
			continue;
		}
		long long lf = n - 2 * i, mn = (long long) i * (i-1)/2;
		if(mn > n) {
			break;
		}
		lf /= 3;
		if(lf < mn) {
			continue;
		}
		ans++;
	}
	cout << ans << endl;
}