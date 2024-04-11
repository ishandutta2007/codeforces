#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 1E6;
int seen[MAXN];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		seen[x] = true;
	}
	int ans = 0;
	for (int i = 1E6; i >= 1; i--)
	{
		if (seen[i])
			continue;
		vector<int> vec;
		for (int j = i + i; j <= 1E6; j += i)
		{
			if (seen[j])
				vec.push_back(j);
		}
		if (vec.size())
		{
			int g = vec[0];
			for (int x : vec)
				g = __gcd(x, g);
			ans += g == i;
		}
	}
	cout << ans << "\n";
	return 0;
}