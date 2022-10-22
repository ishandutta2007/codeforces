#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int mxN=600001, MOD=1e9+9, MOD2=1000000321, p=31, p2=59;

ll ppow[mxN], ppow2[mxN];
set<pair<ll, ll>> hsh[mxN];

pair<ll, ll> cmp_hsh(string s) {
	ll res=0, res2=0;
	for (int i=0; i<s.size(); ++i) {
		res+=(s[i]-'a'+1)*ppow[i];
		res2+=(s[i]-'a'+1)*ppow2[i];
	}
	return {res%MOD, res2%MOD2};
}

int n, q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q;
	ppow[0]=ppow2[0]=1;
	for (int i=1; i<mxN; ++i) {
		ppow[i]=ppow[i-1]*p%MOD;
		ppow2[i]=ppow2[i-1]*p2%MOD2;
	}
	for (int i=0; i<n; ++i) {
		string s;
		cin >> s;
		hsh[s.size()].insert(cmp_hsh(s));
	}
	while(q--) {
		string s;
		cin >> s;
		pair<ll, ll> nhsh=cmp_hsh(s);

		bool pos=0;
		for (int i=0; i<s.size(); ++i) {
			int x=s[i]-'a';
			for (int j=0; j<26; ++j) {
				if (j==x)
					continue;
				//pair<ll, ll> curr={(curr.first+(j-x)*ppow[i]+30ll*MOD)%MOD, (curr.second+(j-x)*ppow2[i]+30ll*MOD2)%MOD2};
				if (hsh[s.size()].find({(nhsh.first+(j-x)*ppow[i]+26ll*MOD)%MOD, (nhsh.second+(j-x)*ppow2[i]+26ll*MOD2)%MOD2})!=hsh[s.size()].end()) {
					pos=1;
					break;
				}
			}
			if (pos)
				break;
		}
		cout << (pos?"YES":"NO") << '\n';
	}
	return 0;
}