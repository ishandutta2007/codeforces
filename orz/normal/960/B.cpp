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
	int n, k, t;
	cin >> n >> k >> t;
	k += t;
	vei a(n), b(n);
	cin >> a >> b;
	multiset<int> m;
	for (int i = 0; i < n; ++i)
		m.insert(-abs(a[i] - b[i]));
	for (int i = 0; i < k; ++i)
	{
		auto mda = m.begin();
		int d = *mda;
		m.erase(mda);
		if (d < 0)
			++d;
		else
			d = -1;
		m.insert(d);
	}
	ll s = 0;
	for (auto i = m.begin(); i != m.end(); ++i)
		s += (((ll)(*i)) * (*i));
	cout << s << '\n';
	return 0;
}