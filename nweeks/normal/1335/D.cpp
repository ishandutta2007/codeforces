#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

	int arr[9][9];
void change(int y, int x)
{
	arr[y][x] = 1+arr[y][x]%9;
}

void solve(void)
{
	for (int i(0); i < 9; ++i)
		for (int j(0); j < 9; ++j)
		{
			char c;
			cin >> c;
			arr[i][j] = c-'0';
		}
	change(0,0);
	change(1, 3);
	change(2, 6);
	change(3, 1);
	change(4, 4);
	change(5, 7);
	change(6, 2);
	change(7, 5);
	change(8, 8);
	for (int i(0); i < 9; ++i)
		for (int j(0); j < 9; ++j)
		{
			cout << arr[i][j];
			if (j==8)
				cout << '\n';
		}
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int __t(1);
	cin >> __t;
	while (__t--)
		solve();
}