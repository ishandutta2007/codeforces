#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
int n, k, a[10000], oc[100];
ar<int, 2> ans[100];
bool vis[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i=0; i<n*k; ++i)
		cin >> a[i], --a[i];
	for (int r=0; r<(n+k-2)/(k-1); ++r) {
		memset(oc, -1, sizeof(oc));
		for (int i=0; i<n*k; ++i) {
			if (vis[a[i]])
				continue;
			if (oc[a[i]]==-1)
				oc[a[i]]=i;
			else {
				ans[a[i]]={oc[a[i]], i};
				vis[a[i]]=1;
				memset(oc, -1, sizeof(oc));
			}
		}
	}
	assert(!count(vis, vis+n, 0));
	for (int i=0; i<n; ++i)
		cout << ans[i][0]+1 << " " << ans[i][1]+1 << "\n";
	return 0;
}