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
	int n;
	cin >> n;
	vpii p(n);
	cin >> p;
	ll ans = 0;
	for (int C = 0; C < 2; ++C)
	{
		vpii q;
		for (int i = 0; i < n; ++i)
		if (((p[i].X ^ p[i].Y) & 1) == C)
			q.push_back(pii((p[i].X + p[i].Y - C) / 2, (p[i].X - p[i].Y - C) / 2));
		int m = sz(q);
		if (m >= 4)
		{
			int L = q[0].X, R = q[0].X;
			for (int i = 0; i < m; ++i)
			{
				L = min(q[i].X, L);
				R = max(q[i].X, R);
			}
			sort(q.begin(), q.end());
			vei left_min(R - L), right_min(R - L), left_max(R - L), right_max(R - L);
			int mn = 10000000, mx = -10000000, k = 0;
			for (int i = L; i < R; ++i)
			{
				while ((k < m) && (q[k].X <= i))
				{
					mn = min(q[k].Y, mn);
					mx = max(q[k].Y, mx);
					++k;
				}
				left_min[i - L] = mn;
				left_max[i - L] = mx;
			}
			mn = 10000000, mx = -10000000, k = 0;
			sort(q.rbegin(), q.rend());
			for (int i = R; i > L; --i)
			{
				while ((k < m) && (q[k].X >= i))
				{
					mn = min(q[k].Y, mn);
					mx = max(q[k].Y, mx);
					++k;
				}
				right_min[i - L - 1] = mn;
				right_max[i - L - 1] = mx;
			}
			for (int i = 0; i < R - L; ++i)
				ans += max(0, min(left_max[i], right_max[i]) - max(left_min[i], right_min[i]));
		}
	}
	cout << ans << '\n';
	return 0;
}