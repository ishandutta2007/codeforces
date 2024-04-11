// 1180d.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int n, m;

int main()
{
	cin >> n >> m;
	int top = 1, bottom = n, left = 1, right = m;
	int x1 = 1, y1 = 1, x2 = n, y2 = m;
	int x[] = { 1, n }, y[] = { 1, m };
	bool reverse = false;
	while (top <= bottom && left <= right)
	{
		if (top == bottom)
		{
			if (!reverse)
			{
				int l = left, r = right;
				while (l <= r)
				{
					cout << top << ' ' << l << '\n';
					l++;
					if (r >= l)
					{
						cout << top << ' ' << r << '\n';
						r--;
					}
					else
					{
						break;
					}
				}
				break;
			}
			else
			{
				int l = left, r = right;
				while (l <= r)
				{
					cout << top << ' ' << r << '\n';
					r--;
					if (r >= l)
					{
						cout << top << ' ' << l << '\n';
						l++;
					}
					else
					{
						break;
					}
				}
				break;
			}
		}
		if (left == right)
		{
			if (!reverse)
			{
				int t = top, b = bottom;
				while (t <= b)
				{
					cout << t << ' ' << left << '\n';
					t++;
					if (b >= t)
					{
						cout << b << ' ' << left << '\n';
						b--;
					}
					else
					{
						break;
					}
				}
				break;
			}
			else
			{
				int t = top, b = bottom;
				while (t <= b)
				{
					cout << b << ' ' << left << '\n';
					b--;
					if (b >= t)
					{
						cout << t << ' ' << left << '\n';
						t++;
					}
					else
					{
						break;
					}
				}
				break;
			}
		}
		if (!reverse)
		{
			cout << x1 << ' ' << y1 << '\n';
			if (y1 + 1 <= right)
			{
				y1++;
			}
			else if (x1 + 1 < bottom)
			{
				x1++;
			}
			cout << x2 << ' ' << y2 << '\n';
			if (y2 - 1 >= left)
			{
				y2--;
			}
			else if (x2 - 1 > top)
			{
				x2--;
			}
			else
			{
				top++;
				bottom--;
				left++;
				right--;
				x1 = bottom;
				y1 = right;
				x2 = top;
				y2 = left;
				reverse = !reverse;
			}
		}
		else
		{
			cout << x1 << ' ' << y1 << '\n';
			if (y1 - 1 >= left)
			{
				y1--;
			}
			else if (x1 - 1 > top)
			{
				x1--;
			}
			cout << x2 << ' ' << y2 << '\n';
			if (y2 + 1 <= right)
			{
				y2++;
			}
			else if (x2 + 1 < bottom)
			{
				x2++;
			}
			else
			{
				top++;
				bottom--;
				left++;
				right--;
				x1 = top;
				y1 = left;
				x2 = bottom;
				y2 = right;
				reverse = !reverse;
			}
		}
	}
}