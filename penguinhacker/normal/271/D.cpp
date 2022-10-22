#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int M1=1e9+9, M2=1e9+321;

int n, k, pref[1501];
ll p1_pow[1501], p2_pow[1501], h1[1501], h2[1501], inv1[1501], inv2[1501];
string s, good;
set<pair<ll, ll>> ans;

ll binPow(ll b, ll p, int M) {
	ll res=1;
	while(p) {
		if(p&1)
			res=res*b%M;
		b=b*b%M;
		p>>=1;
	}
	return res;
}

void cmp_hsh(ll *p_pow, ll *h, ll *inv, int p, int M) {
	p_pow[0]=inv[0]=1;
	inv[1]=binPow(p, M-2, M);
	for (int i=1; i<=n; ++i)
		p_pow[i]=p_pow[i-1]*p%M;
	for (int i=2; i<=n; ++i)
		inv[i]=inv[i-1]*inv[1]%M;
	for (int i=0; i<n; ++i)
		h[i+1]=(h[i]+(s[i]-'a'+1)*p_pow[i+1])%M;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> good >> k, n=s.size();
	//get prefix sums
	for (int i=0; i<n; ++i)
		pref[i+1]=pref[i]+(good[s[i]-'a']=='0');
	cmp_hsh(p1_pow, h1, inv1, 31, M1);
	cmp_hsh(p2_pow, h2, inv2, 53, M2);
	for (int i=0; i<n; ++i) {
		for (int j=i+1; j<=n; ++j) {
			if (pref[j]-pref[i]>k)
				break;
			ll hsh1=inv1[i]*(h1[j]-h1[i]+M1)%M1;
			ll hsh2=inv2[i]*(h2[j]-h2[i]+M2)%M2;
			ans.insert(make_pair(hsh1, hsh2));
		}
	}
	cout << ans.size();
	return 0;
}