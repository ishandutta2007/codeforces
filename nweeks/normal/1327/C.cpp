#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;

	cout << n + m - 3 + n * m << endl;
	for (int i(0); i < n-1; ++i)
		cout << "U";
	
	for (int i(0); i < m-1; ++i)
		cout << "L";

	// At (0,0)
	for (int i(0); i < n; ++i)
	{
		for (int j(0); j < m-1; ++j)
			cout << (i%2 ? "L" : "R");
		if (i < n-1)
			cout << "D";
	}
	cout << endl;
}