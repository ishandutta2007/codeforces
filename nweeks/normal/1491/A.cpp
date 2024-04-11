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

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, q;
	read(n, q);
	vector<int> state(n);
	read(state);
	int nb1(0);
	for (auto v: state)
		nb1 += v;

	while (q--)
	{
		int t, k;
		read(t, k);
		if (t == 1)
		{
			k--;
			state[k] = 1-state[k];
			if (state[k])
				nb1++;
			else
				nb1--;
		}
		else
		{
			if (nb1 >= k)
				writeln(1);
			else
				writeln(0);
		}
	}
}