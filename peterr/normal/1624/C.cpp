#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		priority_queue<int> pq;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			while (x > n)
				x /= 2;
			pq.push(x);
		}
		bool ans = true;
		for (int i = n; i >= 1; i--)
		{
			if (pq.top() != i)
			{
				ans = false;
				break;
			}
			pq.pop();
			while (pq.size() && pq.top() == i)
			{
				pq.push(pq.top() / 2);
				pq.pop();
			}
		}
		cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}