#define _CRT_SECURE_NO_WARNINGS
#define sz(x) ((int)(x.size()))
#define X first
#define Y second
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

template<typename A, typename B>
istream& operator>>(istream& fin, pair<A, B>& p)
{
	fin >> p.X >> p.Y;
	return fin;
}
template<typename A>
istream& operator>>(istream& fin, vector<A>& v)
{
	int n = sz(v);
	for (int i = 0; i < n; ++i)
		fin >> v[i];
	return fin;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll k, d, t;
	cin >> k >> d >> t;
	ll x = (k + d - 1) / d;
	ll cyc = x * d;
	ll en_cyc = cyc + k;
	ll dj = 2 * t;
	ll num_cyc = dj / en_cyc;
	cout << fixed << setprecision(30);
	ll first = en_cyc * num_cyc;
	ll ost = dj - first;
	if (ost <= 2 * k)
		cout << num_cyc * cyc + ((double)(ost)) / 2;
	else
		cout << num_cyc * cyc + k + (ost - 2 * k);
	return 0;
}