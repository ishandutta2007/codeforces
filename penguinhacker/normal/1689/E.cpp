#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

bool vis[3000];

void dfs(int u, vector<int>& a) {
	vis[u]=1;
	if (u<a.size()) {
		for (int i=0; i<30; ++i)
			if ((a[u]&(1<<i))&&!vis[a.size()+i])
				dfs(a.size()+i, a);
	} else {
		for (int i=0; i<a.size(); ++i)
			if (!vis[i]&&(a[i]&(1<<(u-a.size()))))
				dfs(i, a);
	}
}

bool ck(vector<int> a) {
	memset(vis, 0, sizeof(vis));
	dfs(0, a);
	for (int i=0; i<a.size(); ++i)
		if (!vis[i])
			return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		int base=0, ans=69;
		for (int& i : a) {
			cin >> i;
			if (!i)
				++i, ++base;
		}
		vector<int> b;
		for (int i=0; i<n; ++i) {
			if (b.empty()||__builtin_ctz(a[i])>__builtin_ctz(a[b[0]]))
				b={i};
			else if (__builtin_ctz(a[i])==__builtin_ctz(a[b[0]]))
				b.push_back(i);
		}
		if (ck(a)) {
			cout << base << "\n";
			for (int i : a)
				cout << i << " ";
			cout << "\n";
			continue;
		}
		bool ok=0;
		for (int i : b) {
			--a[i];
			if (ck(a)) {
				cout << base+1 << "\n";
				for (int i : a)
					cout << i << " ";
				cout << "\n";
				ok=1;
				break;
			}
			++a[i];
			++a[i];
			if (ck(a)) {
				cout << base+1 << "\n";
				for (int i : a)
					cout << i << " ";
				cout << "\n";
				ok=1;
				break;
			}
			--a[i];
		}
		if (ok)
			continue;
		assert(b.size()>=2);
		--a[b[0]], ++a[b[1]];
		assert(ck(a));
		cout << base+2 << "\n";
		for (int i : a)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}