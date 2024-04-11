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

bool canGet(const vector<int> &arr, int k, int want)
{
	vector<int> pref(SZ(arr)+1);
	for (int i(0); i < SZ(arr); ++i)
		pref[i+1] = pref[i] + (arr[i] >= want ? 1 : -1);
	int bst(1e9);
	for (int i(k); i <= SZ(arr); ++i)
	{
		bst = min(bst, pref[i-k]);
		if (pref[i] > bst)
			return true;
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	read(n, k);
	vector<int> arr(n);
	read(arr);
	int lo(1), up(n);
	while (lo < up)
	{
		int mid = (lo + up + 1)/2;
		if (canGet(arr, k, mid))
			lo = mid;
		else up = mid-1;
	}
	writeln(lo);
}