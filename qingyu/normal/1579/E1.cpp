#include <bits/stdc++.h>

using namespace std;

int n, a[500005];
deque<int> deq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		deq.clear();
		for (int i = 1; i <= n; ++i)
		{
			int x;
			cin >> x;
			if(deq.empty()||x<deq.front())
			{
				deq.push_front(x);
			}
			else deq.push_back(x);
		}
		for (int y : deq) printf("%d ", y);
		putchar('\n');
	}

}