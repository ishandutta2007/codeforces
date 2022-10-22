#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[1000], c[1001];
vector<int> ans;

int MEX() {
	for (int i=0; i<=n; ++i)
		if (c[i]==0) {
			return i;
		}
	return -1;
}

void upd(int pos) {
	int k=MEX();
	--c[a[pos]];
	++c[k];
	a[pos]=k;
	ans.push_back(pos+1);
}

bool sorted() {
	for (int i=1; i<n; ++i)
		if (a[i]<a[i-1])
			return 0;
	return 1;
}

void stuff(int x) { //sort first x things
	for (int i=0; i<x; ++i) {
		if (a[i]==i)
			continue;
		for (int j=i+1; j<x; ++j)
			if (a[j]==i) {
				upd(j);
				break;
			}
		upd(i);
	}
}

void solve() {
	cin >> n;
	ans.clear();
	for (int i=0; i<=n; ++i) c[i]=0;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		c[a[i]]++;
	}
	for (int rep=0; rep<5000; ++rep) {
		if (sorted()) break;
		int k=MEX();
		if (k==n) {
			stuff(n);
			break;
		}
		if (a[k]==k) {
			stuff(k);
		}
		else {
			upd(k);
		}
	}
	/*cout << "\n\n";
	for (int i=0; i<n; ++i)
		cout << a[i] << ' ';*/
	cout << ans.size() << '\n';
	for (int i : ans) cout << i << ' ';
	cout << '\n';
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

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/