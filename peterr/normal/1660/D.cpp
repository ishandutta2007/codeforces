#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
int a[MAXN];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int ptr = 0;
		int best = 0;
		int x = n;
		int y = 0;
		while (ptr < n)
		{
			//cout << "while " << ptr << endl;
			if (a[ptr] == 0)
			{
				ptr++;
				continue;
			}
			int ptr2 = ptr;
			while (ptr2 + 1 < n && a[ptr2 + 1] != 0)
				ptr2++;
			int cnt = 0;
			bool sign = 0;
			for (int i = ptr; i <= ptr2; i++)
			{
				if (abs(a[i]) == 2)
					cnt++;
				if (a[i] < 0)
					sign = !sign;
			}
			if (!sign)
			{
				if (cnt > best)
				{
					best = cnt;
					x = ptr;
					y = n - ptr2 - 1;
				}
			}
			else
			{
				int temp = 0;
				for (int i = ptr; i <= ptr2; i++)
				{
					if (abs(a[i]) == 2)
						temp++;
					if (a[i] >= 0)
						continue;
					if (i < ptr2)
					{
						if (cnt - temp > best)
						{
							best = cnt - temp;
							x = i + 1;
							y = n - ptr2 - 1;
						}
					}
					//cout << "left " << i << endl;
					break;
				}
				temp = 0;
				for (int i = ptr2; i >= ptr; i--)
				{
					if (abs(a[i]) == 2)
						temp++;
					if (a[i] >= 0)
						continue;
					if (i > ptr)
					{
						if (cnt - temp > best)
						{
							best = cnt - temp;
							x = ptr;
							y = n - i;
						}
					}
					//cout << "right " << i << endl;
					break;
				}
			}
			ptr = ptr2 + 1;
		}
		cout << x << " " << y << "\n";
	}
	return 0;
}