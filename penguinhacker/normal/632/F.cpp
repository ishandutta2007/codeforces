#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2500;
int n, a[mxN][mxN];
vector<ll> v;
bitset<mxN> r[mxN], c[mxN];
vector<ar<int, 2>> cur;

void act(ll x) {
	x&=(1ll<<32)-1;
	int i=x/n, j=x%n;
	r[i][j]=r[j][i]=c[i][j]=c[j][i]=1;
	cur.push_back({i, j});
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j)
			cin >> a[i][j];
		if (a[i][i]) {
			cout << "NOT MAGIC";
			return 0;
		}
	}
	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			if (a[i][j]^a[j][i]) {
				cout << "NOT MAGIC";
				return 0;
			}
	v.reserve(n*(n+1)/2);
	cur.reserve(n*(n+1)/2);
	for (int i=0; i<n; ++i)
		for (int j=i; j<n; ++j) {
			ll x=a[i][j];
			v.push_back((x<<32)+i*n+j);
		}
	sort(v.begin(), v.end());
	for (int i=v.size()-1; ~i; --i) {
		act(v[i]);
		while(i&&(v[i]>>32)==(v[i-1]>>32))
			act(v[--i]);
		for (ar<int, 2> x : cur)
			if ((r[x[0]]|c[x[1]]).count()!=n) {
				cout << "NOT MAGIC";
				return 0;
			}
		cur.clear();
	}
	cout << "MAGIC";
	return 0;
}