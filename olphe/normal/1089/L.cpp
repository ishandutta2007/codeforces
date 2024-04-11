#include "bits/stdc++.h"

using namespace std;
using ll = long long int;

int main(){
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n), b(n);
	for(int i=0; i<n; ++i) cin >> a[i];
	for(int i=0; i<n; ++i) cin >> b[i];
	
	vector<vector<ll>> g(k);
	for(int i=0; i<n; ++i) {
		g[a[i]-1].push_back(b[i]);
	}
	ll num = k;
	vector<ll> v;
	for(int i=0; i<k; ++i) {
		if(g[i].size()) num--;
		sort(g[i].begin(), g[i].end());
		for(int j=0; j<(ll)g[i].size()-1; ++j) {
			v.push_back(g[i][j]);
		}
	}
	sort(v.begin(), v.end());
	
	ll ret = 0;
	for(int i=0; i<num; ++i) {
		ret += v[i];
	}
	cout << ret << endl;
	
	return 0;
}