#include <iostream>
#include <cstdlib>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <bitset>
#include <queue>
#include <math.h>
#include <stack>
#include <vector>
#include <string.h>
#include <random>
 
typedef int ll;
 
const ll MOD = 1e9 + 7;
 
using namespace std;

ll n, a[1000000], m;

ll add (ll a, ll b)
{
	ll s = (a + b);
	if (s >= MOD) s -= MOD;

	return s;
}

struct matrix
{
	ll a[2][2];

	matrix ()
	{
		
	}

	matrix (ll z)
	{
		for (ll i = 0; i < 2; i++)
			for (ll j = 0; j < 2; j++)
				a[i][j] = 0;

		if (z)
		{
			a[0][0] = a[1][1] = 1;
		}
	}

	ll* operator [] (ll i)
	{
		return a[i];
	}

	bool operator != (const matrix& b)
	{
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				if (a[i][j] != b.a[i][j]) return true;

		return false;
	}
} pm[200], id_mat (1);

matrix mul (matrix a, matrix b);

void mat_precalc ()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			pm[0][i][j] = 1;
	pm[0][0][0] = 0;

	for (int i = 1; i < 100; i++)
		pm[i] = mul (pm[i-1], pm[i-1]);
}

matrix mul (matrix a, matrix b)
{
	matrix c (0);
	for (ll i = 0; i < 2; i++)
		for (ll j = 0; j < 2; j++)
			for (ll k = 0; k < 2; k++)
			{
				c[i][j] = (c[i][j] + (long long)a[i][k] * b[k][j]) % MOD;
			}

	return c;
}

pair <ll, ll> s_mul (ll fst, ll snd, matrix b)
{
	matrix c (0);
	
	c[0][0] = fst;
	c[0][1] = snd;

	auto k = mul (c, b);

	return {k[0][0], k[0][1]};

}

matrix fib (ll b)
{
	matrix m1 (1);

	for (ll i = 0; b; b>>=1,++i)
		if (b & 1)
			m1 = mul (m1, pm[i]);

	return m1;
}

struct LazySeg
{
	ll start;
	pair <ll, ll> t[400000];

	matrix t_lazy[400000];

	void build (ll n)
	{
		start = 1;

		while (start < n) start <<= 1;

		for (ll i = 0; i < n; i++)
		{
			t_lazy[start + i] = id_mat;
			t[start + i] = s_mul (0, 1, fib (a[i] - 1));
		}

		for (ll i = start - 1; i; i--)
		{
			t_lazy[i] = id_mat;
			t[i] = make_pair (add (t[2 * i].first, t[2 * i + 1].first), 
				add (t[2 * i].second, t[2 * i + 1].second));
		}
	}

	void push (ll node)
	{
		if (t_lazy[node] != id_mat)
		{
			t[node] = s_mul (t[node].first, t[node].second, t_lazy[node]);

			if (node < start)
			{
				t_lazy[2 * node] = mul (t_lazy[2 * node], t_lazy[node]);
				t_lazy[2 * node + 1] = mul (t_lazy[2 * node + 1], t_lazy[node]);
			}

			t_lazy[node] = id_mat;
		}
	}

	void update (ll node, ll tl, ll tr, ll l, ll r, matrix d)
	{
		if (r < tl || tr < l)
		{
		    push(node); 
		    return;
		}

		if (l <= tl && tr <= r)
		{
			t_lazy[node] = mul (t_lazy[node], d);
			push (node);
			return;
		}
		push (node);

		ll tm = (tl + tr) / 2;

		update (2 * node, tl, tm, l, r, d);
		update (2 * node + 1, tm + 1, tr, l, r, d);

		t[node] = {add (t[2 * node].first, t[2 * node + 1].first), 
			add (t[2 * node].second, t[2 * node + 1].second)};
	}

	pair <ll, ll> get (ll node, ll tl, ll tr, ll l, ll r)
	{
		if (r < tl || tr < l) return {0, 0};

        push (node);
		if (l <= tl && tr <= r) return t[node];

		ll tm = (tl + tr) / 2;

		auto a = get (2 * node, tl, tm, l, r);
		auto b = get (2 * node + 1, tm + 1, tr, l, r);

		return {add (a.first, b.first), add (a.second, b.second)};
	}

	void update (ll l, ll r, matrix d)
	{
		update (1, 0, start - 1, l, r, d);
	}

	pair <ll, ll> get (ll l, ll r)
	{
		return get (1, 0, start - 1, l, r);
	}
} tree;

int main ()
{
	cin >> n >> m;

	mat_precalc ();

	for (ll i = 0; i < n; i++)
		scanf ("%d", &a[i]);

	tree.build (n);

	for (ll i = 0; i < m; i++)
	{
		char s[10];

		scanf ("%s", s);

		if (s[0] == '1')
		{
			ll l, r, x;

			scanf ("%d%d%d", &l, &r, &x);

			tree.update (l - 1, r - 1, fib (x));
		}
		else
		{
			ll l, r;

			scanf ("%d%d", &l, &r);

			auto ans = tree.get (l - 1, r - 1);

			printf ("%d\n", ans.second);
		}
	}
}