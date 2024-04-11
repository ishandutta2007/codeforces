#include <bits/stdc++.h>
 
using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 3E6 + 1;
int fac[MAXN + 1];
int invfac[MAXN + 1];
int f[3];
int temp[3];
int res[MAXN + 1];

int modpow(int b, int e)
{
	int ans = 1;
	while (e)
	{
		if (e & 1)
			ans = (int) ((long long) ans * b % MOD);
		e >>= 1;
		b = (int) ((long long) b * b % MOD);
	}
	return ans;
}

int modinv(int x)
{
	return modpow(x, MOD - 2);
}

int choose(int n, int k)
{
	if (k > n)
		return 0;
	int ans = (int) ((long long) fac[n] * invfac[k] % MOD);
	return (int) ((long long) ans * invfac[n - k] % MOD);
}

void add(int& x, int y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
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
	int n, q;
	cin >> n >> q;
	f[0] = f[1] = f[2] = n;
	res[0] = 3 * n;
	int div3 = modinv(3);
	for (int i = 1; i <= 3 * n; i++)
	{
		//cout << "iter " << i << endl;
		temp[2] = choose(3 * n + 1, i + 1);
		add(temp[2], MOD - f[1]);
		add(temp[2], MOD - (int) ((long long) 2 * f[2] % MOD));
		//cout << "before " << temp[2] << endl;
		temp[2] = (int) ((long long) div3 * temp[2] % MOD);

		temp[1] = f[2];
		add(temp[1], temp[2]);

		temp[0] = f[1];
		add(temp[0], f[2]);
		add(temp[0], temp[2]);

		copy(temp, temp + 3, f);
		//cout << "f " << i << " 0 " << f[0] << endl;
		//cout << "f " << i << " 1 " << f[1] << endl;
		//cout << "f " << i << " 2 " << f[2] << endl;
		res[i] = f[0];
	}
	while (q--)
	{
		int x;
		cin >> x;
		cout << res[x] << "\n";
	}
	return 0;
}