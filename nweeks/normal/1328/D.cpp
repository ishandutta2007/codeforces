#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

void solve(void)
{
	int n;
	cin >> n;
	vector<int> types(n);
	for (auto &v : types)
		cin >> v;
	
	bool all_eq = true;
	for (int i(1); i < n; ++i)
		if (types[i] != types[0])
			all_eq = false;
	if (all_eq)
	{
		cout << 1 << '\n';
		for (int i(0); i < n; ++i)
			cout << 1 << ' ';
		cout << '\n';
		return ;
	}
	if (n%2==0)
	{
		cout << 2 << '\n';
		for (int i(0); i < n; ++i)
			cout << 1+i%2 << ' ';
		cout << '\n';
		return ;
	}
	bool exists = false;
	for (int i(0); i < n; ++i)
		exists = exists || (types[i] == types[(i+1)%n]);
	
	if (exists)
	{
		cout << 2 << '\n';
		bool f = false;
		for (int i(0); i < n; ++i)
		{
			cout << (i+f)%2 + 1 << ' ';
			if (!f and types[i] == types[(i+1)%n])
				f = true;
		}
		cout << '\n';
		return ;
	}
	cout << 3 << '\n';
	for (int i(0); i < n; ++i)
	{
		if (i == n-1)
			cout << "3\n";
		else
			cout << 1 + i%2 << ' ';
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
}