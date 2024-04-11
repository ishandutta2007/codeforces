#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define ull unsigned ll

const unsigned long long SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(SEED);

const int mxN=5e5;
int n, a[mxN], c[mxN];
ull ans, v[mxN], p[mxN+1];
vector<int> oc[mxN];
map<ull, int> mp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i], --a[i];
		v[i]=rng();
	}
	++mp[0];
	p[0]=0;
	int l=0;
	for (int i=0; i<n; ++i) {
		p[i+1]=p[i]-c[a[i]]*v[a[i]];
		c[a[i]]=(c[a[i]]+1)%3;
		p[i+1]+=c[a[i]]*v[a[i]];
		if (oc[a[i]].size()>=3) {
			int nl=oc[a[i]].end()[-3];
			while(l<=nl)
				--mp[p[l++]];
		}
		oc[a[i]].push_back(i);
		ans+=mp[p[i+1]]++;
	}
	cout << ans;
	return 0;
}