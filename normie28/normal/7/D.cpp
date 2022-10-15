#include <bits/stdc++.h>
using namespace std;
 
#define FR(i, a, b) for(int i = a; i < b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define PB push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define size(x) (int)x.size()
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define debug(x) cerr<< #x << ": " << x << endl;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
const int N = 1000 * 1000 * 5 + 100;
const ll MOD = 1000 * 1000 * 1000 + 7;
ll pw[N], hsh[N], rhsh[N], pl[N];
int base = 31;
string s;
ll gethash(ll h[], int l, int r)
{
	if(r < l)
		return 0;
	return (h[r] + MOD - ((l?h[l - 1]:0) * pw[r - l + 1]) % MOD) % MOD;
}
 
void fill(ll h[], int a, int b, int c)
{
	ll k = 0;
	for(int i = a; i != b; i += c)
	{
		k = (k * base + s[i]) % MOD;
		h[i] = k;
	}
}
 
int main()
{
	fast;
	cin>> s;
	pw[0] = 1;
	FR(i, 1, size(s) + 10)
		pw[i] = (pw[i - 1] * base) % MOD;
 
	fill(hsh, 0, size(s), 1);
	fill(rhsh, size(s), -1, -1);
	reverse(rhsh, rhsh + size(s));
	
	ll ans = 0;
	FR(i, 0, size(s))
	{
		int t = (i + 1) / 2;
		ll h1 = gethash(hsh, 0, t - 1);
		ll h2 = gethash(rhsh, size(s) - 1 - i, size(s) - 1 - (i + 1 - t));
		if(h1 == h2)
			pl[i] = pl[t - 1] + 1;
		else
			pl[i] = 0;
		ans += pl[i];
	}
	cout<< ans << endl;
}