#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <memory.h>
#include <iomanip>
#include <set>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 2e18 + 123;

#define rep(i, s, t) for (auto i = (s); i < (t); ++(i))
#define per(i, s, t) for (auto i = (s); i >= (t); --(i))
#define sz(x) ((int) x.size())
#define all(x) (x).begin(), (x).end()

template<typename A, typename B> bool mini(A &x, const B &y) {
	if (y < x) {
		x = y;
		return 1;
	}
	return 0;
}

void run();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	run();
#ifdef _DEBUG
	cerr << "OK" << endl;
	while (1);
#endif
	return 0;
}

string s;
int n;

bool check(string &ss)
{
	bool open[256];
	for (int i = 0; i < 256; i++) open[i] = false;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != '*' && ss[i] != s[i])
		{
			return false;
		}
		if (s[i] != '*')
		{
			open[s[i]] = true;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '*' && open[ss[i]])
		{
			return false;
		}
	}
	return true;
}

void run() {
	int m;
	cin >> n;
	cin >> s;
	cin >> m;
	set<char> st;
	for (int i = 0; i < 256; i++)
	{
		st.insert(i);
	}

	for (int i = 0; i < m; i++)
	{
		string ss;
		cin >> ss;
		if (check(ss))
		{
			set<char> sst;
			for (int i = 0; i < n; i++)
			{
				if (s[i] == '*')
				{
					sst.insert(ss[i]);
				}
			}
			//intersect sst and st
			set<char> kek;
			for (char c : st)
			{
				if (sst.find(c) != sst.end())
				{
					kek.insert(c);
				}
			}
			st = kek;
		}
	}
	cout << sz(st);
}