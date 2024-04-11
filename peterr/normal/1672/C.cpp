#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
int a[MAXN];
bool same[MAXN];

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
		int first = n;
		int last = -1;
		for (int i = 0; i < n - 1; i++)
		{
			same[i] = a[i] == a[i + 1];
			if (same[i])
				last = i;
			if (same[i] && first == n)
				first = i;
		}
		if (first == n || first == last)
			cout << "0\n";
		else
			cout << max(1, last - first - 1) << "\n";
	}
	return 0;
}