#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

pair<int, int> cmp(int a, int b)
{
	cout << "? " << a+1 << " " << b+1 << "\n" << flush;
	char c;
	cin >> c;
	if (c == '>')
		return {a, b};
	return {b, a};
}

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--)
	{

		int n;
		cin >> n;

		if (n == 1)
		{
			cout << "! 1 1\n" << flush;
			continue;
		}

		pair<int, int> prv = {-1, -1};
		for (int i=0; i+1<n; i+=2)
		{
			auto c = cmp(i, i+1);
			if (prv == make_pair(-1, -1))
				prv = c;
			else
			{
				auto p = cmp(c.first, prv.first);
				auto q = cmp(c.second, prv.second);
				prv = {p.first, q.second};
			}
		}
		if (n % 2 == 1)
		{
			auto p = cmp(prv.first, n-1);
			auto q = cmp(prv.second, n-1);
			prv = {p.first, q.second};
		}
		cout << "! " << prv.second+1 << " " << prv.first+1 << "\n" << flush;
	}
	return 0;
}