#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int p[10005], n, m, l, r, x, loc;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> p[i];
	while (m--)
	{
		cin >> l >> r >> x;
		l--, x--, r--;
		loc = x - l;
		for (int i = l; i <= r; i++) if (p[i] < p[x]) loc--;
		if (loc == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}