
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
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

#define forn(i, n) for (ll i = 0; i < (ll)n; i++)
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
	ll n;
	cin >> n;
	vector <pii> kr(n);
	forn(i, n)
	{
		cin >> kr[i].first;
		kr[i].second = i;
	}
	sort(kr.begin(), kr.end());
	ll ans = kr[0].first * n;
	ll max1 = 0;
	ll i;
	for (i = 0; ; i++)
	{
		if (i + 1 < n)
			if (kr[i].first == kr[i + 1].first)
				max1 = max(max1, kr[i + 1].second - kr[i].second - 1);
			else
				break;
		else
			break;
	}
	max1 = max(max1, (n + kr[0].second - kr[i].second - 1) % n);
	cout << ans + max1;
	return 0;
}