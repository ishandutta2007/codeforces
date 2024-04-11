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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	char a[9][9];
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			cin >> a[i][j];
	int min1 = 10, min2;
	for (int i = 1; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (a[i][j] == 'W')
			{
				bool f = 1;
				for (int w = i - 1; w >= 0; w--)
					if (a[w][j] == 'B')
						f = 0;
				if (f && min1 == 10)
					min1 = i;
			}
		}
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 8; j++)
		{
			if (a[i][j] == 'B')
			{
				bool f = 1;
				for (int w = i + 1; w < 9; w++)
					if (a[w][j] == 'W')
						f = 0;
				if (f)
					min2 = 8 - i - 1;
			}
		}
	if (min1 <= min2)
		cout << "A";
	else
		cout << "B";
	return 0;
}