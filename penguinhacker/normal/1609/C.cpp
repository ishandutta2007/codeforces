#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, mxA=1e6;
int n, k, a[mxN];
bool p[mxA+1];
vector<int> v[mxN];

void solve() {
	cin >> n >> k;
	for (int i=0; i<k; ++i)
		v[i].clear();
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		v[i%k].push_back(a[i]==1?0:p[a[i]]?1:2);
	}
	ll ans=0;
	for (int i=0; i<k; ++i) {
		int lb=0, cp=0, z=0;
		for (int j=0; j<v[i].size(); ++j) {
			//cout << v[i][j] << " ";
			if (v[i][j]==2) {
				z=0, lb=j+1, cp=0;
				continue;
			}
			z=v[i][j]?0:z+1;
			ans-=z, ans-=v[i][j];
			cp+=v[i][j];
			if (cp==2) {
				while(cp==2)
					cp-=v[i][lb++];
			}
			ans+=j-lb+1;
		}
		//cout << ans << endl;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill(p+2, p+mxA+1, 1);
	for (int i=2; i<=mxA; ++i)
		if (p[i]&&(ll)i*i<=mxA)
			for (int j=i*i; j<=mxA; j+=i)
				p[j]=0;
	//cout << p[19] << endl;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}