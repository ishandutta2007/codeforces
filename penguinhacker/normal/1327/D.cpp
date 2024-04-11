#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, p[200000], c[200000];
bool vis[200000]={};
vector<vector<int>> cyc;

void findCyc(int i) {
	vector<int> v;
	vis[i]=1;
	v.push_back(i);
	int x=i;
	x=p[x];
	while (x!=i) {
		vis[x]=1;
		v.push_back(x);
		x=p[x];
	}
	cyc.push_back(v);
}

int findMinWork(vector<int> x) {
	int k=x.size();
	for (int cnt=1; cnt<=k/2; ++cnt) {
		if (k%cnt!=0)
			continue;
		for (int i=0; i<cnt; ++i) {
			bool pos=1;
			for (int j=i+cnt; j<k; j+=cnt) {
				if (c[x[j]]!=c[x[i]]) {
					pos=0;
					break;
				}
			}
			if (pos)
				return cnt;
		}
	}
	return k;
}

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> p[i], p[i]--;
		vis[i]=0;
	}
	for (int i=0; i<n; ++i)
		cin >> c[i];
	
	cyc.clear();
	for (int i=0; i<n; ++i) {
		if (vis[i])
			continue;
		findCyc(i);
	}
	int ans=1e9;
	for (vector<int> x:cyc)
		ans=min(ans, findMinWork(x));
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}