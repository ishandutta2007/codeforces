#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;

using ll = long long;

template<typename... Args>
void read(Args&... args)
{
	((cin >> args), ...);
}
template<typename T>
void read(vector<T> &vec)
{
	for (auto &v : vec) read(v);
}

void write() {}
template<typename H, typename... T>
void write(const H &h, const T&... t)
{
	cout << h;
	if (sizeof...(t)) {cout << ' '; write(t...);}
}

template<typename T>
void write(const vector<T> &vec)
{
	if (SZ(vec) == 0) return;
	write(vec[0]);
	for (int i(1); i < SZ(vec); ++i)
	{cout << ' '; write(vec[i]);}
}

template<typename... Args>
void writeln(Args... args)
{
	write(args...); cout << '\n';
}

ll pow4(ll x) {return x * x * x * x;}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll l(1);
	for (int i(1); i <= 16; ++i)
		l = lcm(i, l);
	int n,m;
	read(n, m);
	vector<vector<int>> a(n, vector<int>(m));
	for (auto &v : a)
		read(v);
	for (int i(0); i < n; ++i)
		for (int j(0); j < m; ++j)
			a[i][j] = l + ( (i+j)%2 ? pow4(a[i][j]) : 0);
	for (auto &v : a)
		writeln(v);
}