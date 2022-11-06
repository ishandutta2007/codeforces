#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int MOD = 998244353;
int fac[MAXN + 1];
int invfac[MAXN + 1];
string s[MAXN];

void add(int &x, int y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int modpow(int b, int e)
{
	int ans = 1;
	while (e)
	{
		if (e & 1)
			ans = (int) ((long long) ans * b % MOD);
		b = (int) ((long long) b * b % MOD);
		e >>= 1;
	}
	return ans;
}

int modinv(int x)
{
	return modpow(x, MOD - 2);
}

int choose(int n, int k)
{
	if (k < 0 || k > n)
		return 0;
	int ans = (int) ((long long) fac[n] * invfac[k] % MOD);
	return (int) ((long long) ans * invfac[n - k] % MOD);
}

int main()
{
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++)
	{
		fac[i] = (int) ((long long) fac[i - 1] * i % MOD);
	}
	invfac[MAXN] = modinv(fac[MAXN]);
	for (int i = MAXN - 1; i >= 0; i--)
	{
		invfac[i] = (int) ((long long) invfac[i + 1] * (i + 1) % MOD);
	}
	int n;
	cin >> n;
	int lw = 0;
	int lb = 0;
	int rw = 0;
	int rb = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		if (s[i][0] == 'W')
			lw++;
		else if (s[i][0] == 'B')
			lb++;
		if (s[i][1] == 'W')
			rw++;
		else if (s[i][1] == 'B')
			rb++;
	}
	int lu = n - lw - lb;
	int ru = n - rw - rb;
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		//cout << "iter " << i << endl;
		//cout << choose(lu, i - lw) << endl;
		//cout << choose(ru, i - rb) << endl;
		add(ans, (int) ((long long) choose(lu, i - lw) * choose(ru, i - rb) % MOD));
	}
	int overcount = 1;
	bool wb = false;
	bool bw = false;
	bool qw = false;
	bool qb = false;
	bool bq = false;
	bool wq = false;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == "WW" || s[i] == "BB")
			goto skip;
		if (s[i] == "??")
			add(overcount, overcount);
		if (s[i] == "WB")
			wb = true;
		if (s[i] == "BW")
			bw = true;
		if (s[i] == "B?")
			bq = true;
		if (s[i] == "?B")
			qb = true;
		if (s[i] == "W?")
			wq = true;
		if (s[i] == "?W")
			qw = true;
	}
	//cout << "overcount1 " << overcount << endl;
	if (!bw && !bq && !qw)
	{
		add(overcount, MOD - 1);
	}
	if (!wb && !wq && !qb)
	{
		add(overcount, MOD - 1);
	}
	add(ans, MOD - overcount);
	skip:;
	cout << ans << "\n";
	return 0;
}