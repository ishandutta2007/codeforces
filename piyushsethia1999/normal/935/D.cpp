#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

struct fraction
{
	int x, y;
};

int gcd(int x, int y)
{
	if (y == 0)
		return x;
	return gcd(y, x % y);
}

int powermod(int a, int b, int c);

fraction mult(fraction p1, fraction p2, int mod)
{
	fraction f;
	f.x = ((powermod(p1.y, mod - 2, mod) * p1.x) % mod) * ((powermod(p2.y, mod - 2, mod) * p2.x) % mod);
	f.x %= mod;
	f.y = 1;
	return f;
}

fraction add(fraction p1, fraction p2)
{
	fraction f;
	f.x = p1.x * p2.y + p1.y * p2.x;
	f.y = p1.y * p2.y;


	int g = gcd(f.x, f.y);
	f.x /= g;
	f.y /= g;
	return f;
}

int powermod(int a, int b, int c)
{
	int res = 1;
	while (b) {
		if (b & 1)
			res = (res * a) % c;
		a = (a * a) % c;
		b >>= 1ll;
	}
	return res;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
#ifdef PIYUSH_HOME
	I_O;
#else
#define print(...) 0
#endif
	int mod = 1e9 + 7;
	int n; cin >> n;
	int m; cin >> m;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	vector<int> b(n); for (int o = 0; o < n; o++) { cin >> b[o]; }
	fraction p;
	p.x = 0;
	p.y = 1;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == 0 || b[i] == 0)
			break;
		else if (a[i] < b[i])
		{
			cout << 0;
			return 0;
		}
		else if (a[i] > b[i])
		{
			cout << 1;
			return 0;
		}
	}
	fraction p1;
	p1.x = 1;
	p1.y = 1;
	fraction temp;
	temp.y = m;
	fraction temp2;
	temp2.x = m - 1;
	temp2.y = 2 * m;
	print(temp2.x, temp2.y);
	std::vector<fraction> vii;
	for (int i = 0; i < n; ++i)
	{
		print(p1.x, p1.y);
		print(p.x, p.y);
		print(a[i], b[i]);
		if (a[i] != 0 && a[i] < b[i])
			break;
		else if (b[i] != 0 && a[i] > b[i]) {
			vii.pb(p1);
			break;
		}
		else if (a[i] == 0 && b[i] != 0) {
			temp.x = m - b[i];
			vii.pb(mult(p1, temp, mod));
			temp.x = 1;
			p1 = mult(p1, temp, mod);
		}
		else if (a[i] != 0 && b[i] == 0) {
			temp.x = a[i] - 1;
			vii.pb(mult(p1, temp, mod));
			temp.x = 1;
			p1 = mult(p1, temp, mod);
		}
		else if (a[i] == 0 && b[i] == 0) {
			vii.pb(mult(p1, temp2, mod));
			temp.x = 1;
			p1 = mult(p1, temp, mod);
		}
		print(p1.x, p1.y);
		print(p.x, p.y);
		print("ok");
	}
	print(p.x, p.y);
	int res = 0;
	for (int i = 0; i < vii.size(); ++i)
		res = (res + (vii[i].x * powermod(vii[i].y, mod - 2, mod)) % mod) % mod;
	// cout << (p.x * powermod(p.y, mod - 2, mod)) % mod << "\n";
	cout << res;
}