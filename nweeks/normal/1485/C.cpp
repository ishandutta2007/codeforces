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

ll solve()
{
	ll x,y;
	read(x,y);
	ll sol(0);
	for (ll r(1); r * r <= x; ++r)
	{
		ll up = min(y, x/r-1);
		ll lo = r+1;
		if (lo <= up)
			sol += up - lo + 1;
	}
	return sol;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	read(t);
	while(t--)
		writeln(solve());
}