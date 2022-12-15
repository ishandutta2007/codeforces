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

int askQuery(int l, int r)
{
	cout << "? " << l << ' ' << r << endl;
	int ret;
	cin >> ret;
	return ret;

}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	read(n);
	int lo(1), up(n);
	int posSecond = askQuery(1, n);
	while (up - lo > 1)
	{
		int mid = (lo + up +1)/2;
		if (posSecond <= mid)
		{
			if (mid == 1 or askQuery(1, mid) != posSecond)
				lo = mid+1;
			else
				up = mid;
		}
		else
		{
			if (mid == n or askQuery(mid, n) != posSecond)
				up = mid-1;
			else
				lo = mid;
		}
	}
	int ret = lo;
	if (lo < up)
	{
		assert(lo + 1 == up);
		if (askQuery(lo, lo+1) == lo) ret = lo+1;
		else ret = lo;
	}
	cout << "! " << ret << endl;
}