#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

bool solve()
{
	int lft, rgt, down, up;
	cin >> lft >> rgt >> down >> up;
	int x, y, x1, y1 , x2, y2;
	cin >> x >>  y >> x1 >> y1 >>  x2 >> y2;

	if (x == x1 and x == x2 and lft+rgt > 0)
		return false;
	if (y == y1 and y == y2 and down + up > 0)
		return false;
	if (rgt - lft + x < x1 or rgt - lft + x > x2)
		return false;
	if (up - down + y < y1 or up - down + y > y2)
		return false;
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		cout << (solve() ? "YES" : "NO") << "\n";
}