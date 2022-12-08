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
	int n;
	cin >> n;
	vector <int> av(n), an(n), b(n);
	for (int i = 1; i < n; i++)
		cin >> av[i];
	av[0] = 0;
	for (int i = 0; i < n - 1; i++)
		cin >> an[i];
	an[n - 1] = 0;
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 1; i < n; i++)
		av[i] += av[i - 1];
	for (int i = n - 2; i >= 0; i--)
		an[i] += an[i + 1];
	int min1 = 1000000000;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			min1 = min(min1, b[j] + av[j] + an[j] + av[i] + an[i] + b[i]);
	cout << min1;
	return 0;
}