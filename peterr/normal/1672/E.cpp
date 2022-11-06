#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2000;

int test[6] = {5, 2, 7, 3, 5, 6};

int query(int x)
{
	cout << "? " << x << endl;
	int q;
	cin >> q;
	//if (x < 7)
		//return 0;
	//int ptr = 0;
	//for (int i = 1; i <= MAXN; i++)
	//{
		//int sz = x - test[ptr];
		//ptr++;
		//while (ptr < 6 && sz >= test[ptr] + 1)
		//{
			//sz -= 1 + test[ptr];
			//ptr++;
		//}
		//if (ptr == 6)
		//{
			//q = i;
			//break;
		//}
	//}
	return q;
}

void output(int ans)
{
	cout << "! " << ans << endl;
}

int main()
{
	int n;
	cin >> n;
	int lo = 1;
	int hi = MAXN * MAXN + MAXN;
	while (lo < hi)
	{
		int mid = (lo + hi) / 2;
		if (query(mid) == 1)
			hi = mid;
		else
			lo = mid + 1;
	}
	//cout << "end lo " << lo << endl;
	lo -= n - 1;
	int ans = lo + n - 1;
	for (int i = 2; i <= n; i++)
	{
		//cout << "checking " << i << endl;
		int best = lo + n - i;
		int w = (best + i - 1) / i;
		int q = query(w);
		if (q)
			ans = min(ans, q * w);
	}
	output(ans);
	return 0;
}