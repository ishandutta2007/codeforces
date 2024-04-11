#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;
typedef long long ll; 

template<ll P>
struct Fp
{
	ll n;
	Fp() : n(0) {}
	Fp(ll _n) : n(((_n%P)+P)%P) {}
	inline Fp operator+(Fp other) const {return Fp(n + other.n);}
	inline Fp operator-(Fp other) const {return Fp(n - other.n);}
	inline Fp operator*(Fp other) const {return Fp(n * other.n);}
};
using Mint = Fp<ll(1e9 + 7)>;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, k, q;
	cin >> n >> k >> q;
	vector<vector<Mint>> cntPaths(k+1, vector<Mint>(n));
	for (int len(0); len <= k; ++len)
		for (int startPos(0); startPos < n; ++startPos)
		{
			if (!len) cntPaths[len][startPos] = 1;
			else
			{
				if (startPos) 
					cntPaths[len][startPos] = cntPaths[len][startPos] + cntPaths[len-1][startPos-1];
				if (startPos < n-1)
					cntPaths[len][startPos] = cntPaths[len][startPos] + cntPaths[len-1][startPos+1];
			}
		}
	vector<Mint> cntPass(n);
	for (int i(0); i < n; ++i)
		for (int when(0); when <= k; ++when)
			cntPass[i] = cntPass[i] + cntPaths[when][i] * cntPaths[k-when][i];
	vector<ll> a(n);
	for (auto &v : a) cin >> v;
	Mint ret(0);
	for (int i(0); i < n; ++i)
		ret = ret + Mint(a[i]) * cntPass[i];
	while (q--)
	{
		int i, x;
		cin >> i >> x;
		--i;
		ret = ret - Mint(a[i]) * cntPass[i];
		a[i] = x;
		ret = ret + Mint(a[i]) * cntPass[i];
		cout << ret.n << '\n';
	}
}