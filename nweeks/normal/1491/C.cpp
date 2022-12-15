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
	int nbTramp;
	read(nbTramp);
	vector<ll> tramp(nbTramp);
	vector<ll> freePass(nbTramp);
	read(tramp);
	ll sol(0);
	for (int i(0); i < nbTramp; ++i)
	{
		ll nbNecessaire = tramp[i] - 1;
		sol += max(0LL, nbNecessaire - freePass[i]);
		freePass[i] -= min(nbNecessaire, freePass[i]);
		for (int j(2); i+j < nbTramp and j <= tramp[i]; ++j)
			freePass[i+j]++;
		if (i + 1< nbTramp)
			freePass[i+1] += freePass[i];
	}
	return(sol);
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	read(t);
	while (t--)
		writeln(solve());
}