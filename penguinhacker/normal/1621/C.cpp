#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e4;
int n, ans[mxN];
bool vis[mxN];

int ask(int x) {
	cout << "? " << x << endl;
	int y;
	cin >> y;
	if (!y)
		exit(0);
	return y-1;
}

void solve() {
	cin >> n;
	memset(vis, 0, n);
	for (int i=0; i<n; ++i) {
		if (vis[i])
			continue;
		vector<int> cyc;
		while(1) {
			int x=ask(i+1);
			if (cyc.empty()||cyc[0]!=x) {
				cyc.push_back(x);
				vis[x]=1;
			} else
				break;
		}
		for (int i=0; i<cyc.size(); ++i)
			ans[cyc[i]]=cyc[(i+1)%cyc.size()];
		//auto it=find(cyc.begin(), cyc.end(), i);
		//assert(it!=cyc.end());
	}
	cout << "!";
	for (int i=0; i<n; ++i)
		cout << " " << ans[i]+1;
	cout << endl;
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