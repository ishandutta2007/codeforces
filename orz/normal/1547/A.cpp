#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	int t;
	cin >> t;
	for (int j = 0; j < t; j++)
	{
		vector<vector<int>> v(3, vector<int>(2));
		v.assign(3, vector<int>(2));
		cin >> v[0][0] >> v[0][1] >> v[1][0] >> v[1][1] >> v[2][0] >> v[2][1];
		if (v[0][1] == v[1][1] and v[1][1] == v[2][1] and ((v[0][0] < v[2][0] and v[2][0] < v[1][0]) or (v[0][0] > v[2][0] and v[2][0] > v[1][0])))
			cout << abs(v[1][0] - v[0][0]) + abs(v[1][1] - v[0][1]) + 2;
		else if (v[0][0] == v[1][0] and v[1][0] == v[2][0] and ((v[0][1] < v[2][1] and v[2][1] < v[1][1]) or (v[0][1] > v[2][1] and v[2][1] > v[1][1])))
			cout << abs(v[1][0] - v[0][0]) + abs(v[1][1] - v[0][1]) + 2;
		else
			cout << abs(v[1][0] - v[0][0]) + abs(v[1][1] - v[0][1]);
		cout << '\n';
	}
}