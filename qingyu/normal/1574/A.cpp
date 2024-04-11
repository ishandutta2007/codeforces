#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		int n; cin >> n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
				cout << '(';
			for (int j = 0; j < i; ++j)
				cout << ')';
			for (int j = 0; j < n - i; ++j)
				cout << '(';
			for (int j = 0; j < n - i; ++j)
				cout << ')';
			cout << '\n';
		}
	}
}