#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 1E5;
int a[MAXN];
int b[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		copy(a, a + n, b);
		sort(b, b + n);
		map<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			mp[b[i]] = i;
			//cout << "mp " << b[i] << " = " << mp[b[i]] << endl;
		}
		int ans = 0;
		int ptr = 0;
		while (ptr < n)
		{
			ans++;
			int r = mp[a[ptr]] + 1;
			while (ptr + 1 < n && (mp[a[ptr + 1]] == r))
			{
				r++;
				ptr++;
			}
			ptr++;
			//cout << "ptr " << ptr << endl;
		}
		cout << (k >= ans ? "Yes" : "No") << "\n";
	}
	
	return 0;
}