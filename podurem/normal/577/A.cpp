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
	int n, x, ans = 0;
	cin >> n >> x;
	unordered_set <int> s;
	for (int i = 1; i < (int)sqrt(x) + 1; i++)
		if (x % i == 0 && x / i <= n && s.find(i) == s.end() && i <= n)
		{
			ans++;
			s.insert(i);
			if (s.find(x / i) == s.end())
				ans++;
		}
	cout << ans;
	return 0;
}