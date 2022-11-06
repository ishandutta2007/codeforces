#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	vector<string> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	int cnt = 0;
	for (int i = 1; i < n-1; ++i)
	{
		for (int j = 1; j < n-1; ++j)
		{
			if(a[i][j] == 'X' && a[i-1][j-1] == 'X' && a[i+1][j+1] == 'X' && a[i+1][j-1] == 'X' &&a[i-1][j+1] == 'X')
				cnt++;
		}
	}
	cout << cnt;
}