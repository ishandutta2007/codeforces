#include <bits/stdc++.h>

const int N = 1e6 + 50;
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int n, s;
		cin >> n >> s;
		int cnt = n / 2 + 1;
		cout << s / cnt << "\n";
	}
	
}