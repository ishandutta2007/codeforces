#define _CRT_SECURE_NO_WARNINGS
#define ll long long
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct part
{
	ll s, ok, neok, n;
	part(const ll& s, const ll& ok, const ll& neok, const ll& n) : s(s), ok(ok), neok(neok), n(n) {}
	inline bool operator<(const part& y) const
	{
		if (neok != y.neok)
			return neok < y.neok;
		return n < y.n;
	}
};

int main()
{
	//freopen("c.in", "r", stdin);
	//freopen("c.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, s, m = 0, m1 = 0, m2 = 0, norm1 = 0, norm2 = 0;
	cin >> n >> s;
	vector<ll> l(n), a(n), b(n);
	vector<part> s1, s2;
	for (int i = 0; i < n; ++i)
	{
		cin >> l[i] >> a[i] >> b[i];
		m += l[i];
		if (a[i] >= b[i])
		{
			s1.push_back(part(l[i], a[i], a[i] - b[i], i));
			m1 += l[i];
			norm1 += a[i] * l[i];
		}
		else
		{
			s2.push_back(part(l[i], b[i], b[i] - a[i], i));
			m2 += l[i];
			norm2 += b[i] * l[i];
		}
	}
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	m = (m + s - 1) / s * s;
	//cout << m << '\n';
	//cout << norm1 << ' ' << norm2 << '\n';
	ll itog1 = norm1, itog2 = norm2;
	if ((m1 + s - 1) / s * s + (m2 + s - 1) / s * s <= m)
		cout << norm1 + norm2 << '\n';
	else
	{
		int g1 = m1 % s;
		int i = 0;
		while (g1)
		{
			if (s1[i].s)
			{
				itog1 -= s1[i].neok;
				--g1;
				--s1[i].s;
			}
			else
				++i;
		}

		int g2 = m2 % s;
		i = 0;
		while (g2)
		{
			if (s2[i].s)
			{
				itog2 -= s2[i].neok;
				--g2;
				--s2[i].s;
			}
			else
				++i;
		}
		//cout << norm1 + itog2 << ' ' << norm2 + itog1 << '\n';
		cout << max(norm1 + itog2, norm2 + itog1);
	}

	return 0;
}