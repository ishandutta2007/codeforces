#define _CRT_SECURE_NO_WARNINGS
#define sz(x) ((int)(x.size()))
#define X first
#define Y second
#define UM unordered_map
#pragma comment(linker, "/STACK:66777216")
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<int> vei;
typedef vector<ll> vel;
typedef vector<vei> vvei;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

template<typename A>
istream& operator>>(istream& fin, vector<A>& v)
{
	int n = sz(v);
	for (int i = 0; i < n; ++i)
		fin >> v[i];
	return fin;
}
template<typename A, typename B>
istream& operator>>(istream& fin, pair<A, B>& v)
{
	fin >> v.X >> v.Y;
	return fin;
}

const int C = 60;
int level(const ll& l)
{
	if (l > 1)
		return 1 + level(l >> 1);
	else
		return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	cin >> q;
	vel v(C);
	for (int I = 0; I < q; ++I)
	{
		int t;
		cin >> t;
		ll x;
		cin >> x;
		int l = level(x);
		
		if (t == 1)
		{
			ll k;
			cin >> k;
			k = k & ((1ll << l) - 1);
			v[l] = (v[l] - k) & ((1ll << l) - 1);
		}
		else if (t == 2)
		{
			ll k;
			cin >> k;
			k = k & ((1ll << l) - 1);
			for (int i = l; i < C; ++i)
				v[i] = (v[i] - (k << (i - l))) & ((1ll << i) - 1);
		}
		else
		{
			ll e = (((x - v[l]) & ((1ll << l) - 1)) | (1ll << l));
			while (l)
			{
				cout << (((e + v[l]) & ((1ll << l) - 1)) | (1ll << l)) << ' ';
				--l;
				e >>= 1;
			}
			cout << "1\n";
		}
		/*
		cout << "!!! ";
		for (int i = 0; i < 5; ++i)
			cout << v[i] << ' ';
		cout << '\n';
		*/
	}
	return 0;
}