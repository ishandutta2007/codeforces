#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

void solve(void)
{
	int lines, cols;
	cin >> lines >> cols;

	for (int i(0); i < lines; ++i)
	{
		for (int col(0); col < cols-1; ++col)
			cout << "B";
		if (i == lines-1)
			cout << "W";
		else
			cout << "B";
		cout << "\n";
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