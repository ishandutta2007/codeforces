#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
		I_O;
	#else
	#define print(...) 0
	#endif
	int n, m;
	cin >> n >> m;
	int x, y;
	std::vector<int> a(m+1, 0);
	for (int j = 0; j < n; ++j)
		{
			cin >> x >> y;
			for (int i = x; i <= y; ++i)
			{
				a[i] = 1;
			}
		}	
	int c = 0;
	for (int i = 1; i <= m; ++i)
	{
		if(!a[i])
			c++;
	}
	cout << c << '\n';
	for (int i = 1; i <= m; ++i)
	{
		if(!a[i])
			cout << i << " ";
	}
}