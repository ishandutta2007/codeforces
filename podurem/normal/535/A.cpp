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
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef set <ll> sll;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define forq(i, q, n) for (int i = (int)q; i < (int)n; ++i)
#define forb(i, n, q) for (int i = (int)n; i >= (int)q; ++i)
#define fornll(i, n) for (ll i = 0; i < (ll)n; ++i)
#define forqll(i, q, n) for (ll i = (ll)q; i < (ll)n; ++i)
#define forbll(i, n, q) for (ll i = (ll)n; i >= (ll)q; ++i)
#define mk make_pair
#define X first
#define Y second
#define psh push_back
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define TASK ""

const int INF = (int)1e9 + 7;
const int MOD = (int)1e9 + 7;
const double EPS = (double)1e-8;

string zap1(int n)
{
	if (n == 0)
		return "zero";
	if (n == 1)
		return "one";
	if (n == 2)
		return "two";
	if (n == 3)
		return "three";
	if (n == 4)
		return "four";
	if (n == 5)
		return "five";
	if (n == 6)
		return "six";
	if (n == 7)
		return "seven";
	if (n == 8)
		return "eight";
	if (n == 9)
		return "nine";
}

string zap2(int n)
{
	if (n == 10)
		return "ten";
	if (n == 11)
		return "eleven";
	if (n == 12)
		return "twelve";
	if (n == 13)
		return "thirteen";
	if (n == 14)
		return "fourteen";
	if (n == 15)
		return "fifteen";
	if (n == 16)
		return "sixteen";
	if (n == 17)
		return "seventeen";
	if (n == 18)
		return "eighteen";
	if (n == 19)
		return "nineteen";
}

string zap3(int n)
{
	if (n == 2)
		return "twenty";
	if (n == 3)
		return "thirty";
	if (n == 4)
		return "forty";
	if (n == 5)
		return "fifty";
	if (n == 6)
		return "sixty";
	if (n == 7)
		return "seventy";
	if (n == 8)
		return "eighty";
	if (n == 9)
		return "ninety";
}

int main()
{
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	if (n < 10)
	{
		cout << zap1(n);
		return 0;
	}
	if (n < 20)
	{
		cout << zap2(n);
		return 0;
	}
	if (n % 10 != 0)
		cout << zap3(n / 10) << "-" << zap1(n % 10);
	else
		cout << zap3(n / 10);
	return 0;
}