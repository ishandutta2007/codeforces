#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

const int MAXN = 2e5;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	int test;
	cin >> test;
	while (test--)
	{
		string t;
		cin >> t;
		int n = t.size();

		int l(0);
		int r = n-1;
		while (l < n and t[l] == '0')
			l++;

		while (r > l and t[r] == '0')
			r--;

		int cnt(0);
		for (int i(l); i < r; ++i)
			cnt += (t[i] == '0');
		cout << cnt << endl;
	}
}