#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mk make_pair
#define psh push_back
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define TASK ""

const int INF = (int)1e9 + 7;

int main()
{
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string s;
	cin >> n >> s >> s;
	if (s == "week")
	{
		if (n == 1)
			cout << 52;
		if (n == 2)
			cout << 52;
		if (n == 3)
			cout << 52;
		if (n == 4)
			cout << 52;
		if (n == 5)
			cout << 53;
		if (n == 6)
			cout << 53;
		if (n == 7)
			cout << 52;
	}
	else
	{
		if (n <= 29)
			cout << 12;
		if (n == 30)
			cout << 11;
		if (n == 31)
			cout << 7;
	}
	return 0;
}