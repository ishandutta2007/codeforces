#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD=1e9+7;
int binPow(ll b, int p=MOD-2) {
	ll res=1;
	while(p>0) {
		if (p&1) res=res*b%MOD;
		b=b*b%MOD;
		p>>=1;
	}
	return res;
}

vector<ll> f={1}, iF={1};
ll C(int a, int b) {
	if (a<0||b<0||b>a) return 0;
	assert(a<=(int)5e6);
	while(f.size()<=a) {
		int x=f.size();
		f.push_back(f.back()*x%MOD);
		iF.push_back(iF.back()*binPow(x)%MOD);
	}
	return f[a]*iF[b]%MOD*iF[a-b]%MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int n=s.size();
		int sum=0;
		for (char c: s)
			sum+=c-'a'+1;
		/*vector<int> dp
		for (int i=0; i<n; ++i) {
			
		}*/
		ll ans=0;
		for (int i=0; i<=n; ++i) {
			int sign=i%2==0?1:-1;
			int inc=sign*C(n, i)*C(sum-26*i-1, n-1)%MOD;
			if (inc<0) inc+=MOD;
			ans=(ans+inc)%MOD;
		}
		ans=(ans-1+MOD)%MOD;
		cout << ans << "\n";
	}
	return 0;
}