#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int M=1e9+7;
int n, a[100000];
map<int, int> mp;
 
int binPow(ll b, int p = M - 2) {
	ll res = 1;
	while(p > 0) {
		if (p & 1) res = res * b % M;
		b = b * b % M;
		p >>= 1;
	}
	return res;
}
 
vector<ll> f = {1}, iF = {1};
ll C(int a, int b) {
	if (a < 0 || b < 0 || b > a) return 0;
	assert(a <= (int)5e6);
	while(f.size() <= a) {
		int x = f.size();
		f.push_back(f.back() * x % M);
		iF.push_back(iF.back() * binPow(x) % M);
	}
	return f[a] * iF[b] % M * iF[a-b] % M;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	C(100005, 0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i], ++mp[a[i]];
	ll s=accumulate(a, a+n, 0ll);
	if (s%n) {
		cout << 0;
		return 0;
	}
	int avg=s/n;
	int ne=0, p=0, z=0;
	for (int i=0; i<n; ++i) {
		ne+=a[i]<avg;
		p+=a[i]>avg;
		z+=a[i]==avg;
	}
	if (z==n) {
		cout << 1;
		return 0;
	}
	if (ne<=1||p<=1) {
		ll ans=f[n];
		for (auto& x : mp)
			ans=ans*iF[x.second]%M;
		cout << ans;
		return 0;
	}
	ll ans=f[ne]*f[p]%M*C(n, z)%M*2%M;
	for (auto& x : mp)
		if (x.first^avg)
			ans=ans*iF[x.second]%M;
	cout << ans;
	return 0;
}