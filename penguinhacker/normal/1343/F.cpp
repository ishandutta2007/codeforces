#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

// idea: fix which segment comes first and keep going
// complexity: n segments can come first ig... maybe o(n^3/64) for each

int n;
vector<int> v[200];
bool used[200];

bool check(int st, vector<int> ans) {
	memset(used, 0, sizeof(used));
	used[st]=1;
	ans.resize(n);
	for (int i=2; i<n; ++i) {
		bool ok=0;
		for (int j=0; j<n-1; ++j) {
			if (!used[j]&&v[j].size()<=i+1) {
				vector<int> cnt(n);
				for (int k=0; k<v[j].size()-1; ++k)
					++cnt[ans[i-k-1]];
				int one=-1;
				for (int k : v[j])
					if (++cnt[k]==1) {
						if (one!=-1) {
							one=-1;
							break;
						}
						one=k;
					}
				if (one^-1) {
					//if (ans[0]==3)
					//	cout << one << " " << j << "\n";
					ans[i]=one;
					used[j]=ok=1;
					break;
				}
			}
		}
		if (!ok)
			return 0;
	}
	for (int i : ans)
		cout << i+1 << " ";
	cout << "\n";
	return 1;
}

void solve() {
	cin >> n;
	for (int i=0; i<n-1; ++i) {
		int k;
		cin >> k;
		v[i].resize(k);
		for (int& j : v[i])
			cin >> j, --j;
	}
	for (int i=0; i<n-1; ++i) {
		if (v[i].size()==2) {
			if (check(i, {v[i][0], v[i][1]})||check(i, {v[i][1], v[i][0]}))
				return;
		}
	}
	//cout << "UH OH BAD\n";
	assert(0);
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