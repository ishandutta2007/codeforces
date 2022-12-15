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

bool solve()
{
	ll u, v;
	read(u, v);
	vector<vector<bool>> dp(31, vector<bool>(31));
	dp[0][0] = true;
	for (int iRestant(1); iRestant <= 30; ++iRestant)
		for (int bitGarde(0); bitGarde <= 30; ++bitGarde)
		{
			int p = 1 << (30 - iRestant);
			if (!(p&u) and bitGarde > 1)
				dp[iRestant][bitGarde] = dp[iRestant][bitGarde-1];
			if (p & v)
			{
				if (bitGarde and !dp[iRestant][bitGarde])
					dp[iRestant][bitGarde] = dp[iRestant-1][!!(p&u) + bitGarde-1];
				if (!dp[iRestant][bitGarde])
						dp[iRestant][bitGarde] = (p&u) and dp[iRestant-1][bitGarde];
			}
			else if (bitGarde < 30 and !dp[iRestant][bitGarde])
				dp[iRestant][bitGarde] = 	dp[iRestant-1][bitGarde + !!(p & u)];
		}
	return dp[30][0];
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	read(t);
	while (t--)
		writeln(solve() ? "YES" : "NO");
}