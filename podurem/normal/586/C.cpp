#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long int1;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int1 n;
	cin >> n;
	vector <int1> plk(n), plkor(n), resh(n), ans;
	for (int1 i = 0; i < n; i++)
		cin >> plk[i] >> plkor[i] >> resh[i];
	for (int1 i = 0; i < n; i++)
	{
		if (resh[i] >= 0)
		{
			ans.push_back(i + 1);
			int1 kol = plk[i];
			int1 v = 0;
			for (int1 j = i + 1; j < n && kol > 0; j++)
				if (resh[j] - v >= 0)
				{
					resh[j] -= kol;
					kol--;
				}
				else
					v += plkor[j];
		}
		else
			for (int1 j = i + 1; j < n; j++)
				resh[j] -= plkor[i];
	}
	cout << ans.size() << "\n";
	for (int1 i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}