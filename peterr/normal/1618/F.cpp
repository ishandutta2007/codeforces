#include <bits/stdc++.h>
 
using namespace std;

long long rev(long long x)
{
	int ptr = 62;
	while (!(x & (1LL << ptr)))
		ptr--;
	long long ans = 0;
	long long two = 1;
	while (ptr >= 0)
	{
		if (x & (1LL << ptr))
			ans += two;
		two += two;
		ptr--;
	}
	return ans;
}

bool solve2(long long x, long long y)
{
	if (x == y)
		return true;
	//cout << "solve2 " << x << " " << y << endl;
	int x_popcount = __builtin_popcountll(x);
	int y_popcount = __builtin_popcountll(y);
	if (x_popcount >= y_popcount)
		return false;
	int diff = y_popcount - x_popcount;
	int ind = 64 - __builtin_clzll(x);
	//cout << "\tdiff " << diff << endl;
	//cout << "\tind " << ind << endl;
	for (int i = 0; i <= diff && ind + diff <= 62; i++)
	{
		//cout << "\ti " << i << endl;
		long long temp = x;
		//cout << "\tpretemp " << temp << endl;
		for (int j = 0; j < diff - i; j++)
		{
			temp += 1LL << (ind + j + i);
		}
		//cout << "\tposttemp " << temp << endl;
		if (temp == y)
		{
			//cout << "yes from " << x << " " << y << endl;
			//cout << "diff " << diff << endl;
			//cout << "i " << i << endl;
			return true;
		}
		x += x;
		x++;
	}
	return false; 
}

bool solve(long long x, long long y)
{
	if (x == y)
		return true;
	if (x & 1)
		return solve2(x, y) || solve2(rev(x), y);
	else
		return solve(rev(2 * x), y) || solve(rev(2 * x + 1), y);
}

int main()
{
	long long x, y;
	cin >> x >> y;
	cout << (solve(x, y) ? "YES" : "NO") << "\n";
	return 0;
}