#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll u, v;
	cin >> u >> v;

	if (u > v or v%2 != u%2)
	{
		cout << -1 << endl;
		return 0;
	}

	if (u == v and u == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	if (u== v)
	{
		cout << 1 << endl << u << endl;
		return 0;
	}

	if ((((u+v)/2)&u) == u)
	{
		cout << 2 << endl << (u+v)/2 << ' ' << (v-u)/2 << endl;
		return 0;
	}
	
	cout << 3 << endl;
	cout << u << ' ' << (v-u)/2 << ' ' << (v-u)/2 << endl;
}