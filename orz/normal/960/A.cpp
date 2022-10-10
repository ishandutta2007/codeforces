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
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<int> vei;
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s;
	getline(cin, s);
	int a = 0, b = 0, c = 0, d = 0;
	for (int i = 0; i < sz(s); ++i)
	if (s[i] == 'a')
		++a;
	else if (s[i] == 'b')
		++b;
	else if (s[i] == 'c')
		++c;
	else
		++d;
	if (d)
		cout << "NO\n";
	else
	{
		bool kek = (a && b && ((a == c) || (b == c)));
		for (int i = 0; kek && (i < a); ++i)
			kek = (s[i] == 'a');
		for (int i = a; kek && (i < a + b); ++i)
			kek = (s[i] == 'b');
		for (int i = a + b; kek && (i < a + b + c); ++i)
			kek = (s[i] == 'c');
		cout << (kek ? "YES\n" : "NO\n");
	}
	return 0;
}