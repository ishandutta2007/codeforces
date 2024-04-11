#include <iostream>
using namespace std;

long double a[3];
int h, m, s, t1, t2, c = 0;

int main() {
	cin >> h >> m >> s >> t1 >> t2;
	t1 = t1 * 30 % 360, t2 = t2 * 30 % 360;
	a[0] = s * 6;
	a[1] = m * 6 + a[0] / 60.0;
	a[2] = h * 30 + a[1] / 12.0;
	
	for (int i = 0; i < 3; i++) while (a[i] >= 360.0) a[i] -= 360.0;
	if (t1 > t2) swap(t1, t2);
	
	for (int i = 0; i < 3; i++) c += (t1 < a[i] && a[i] < t2);
	if (c % 3 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}