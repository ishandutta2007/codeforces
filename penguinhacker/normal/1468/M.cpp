#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, B=280;
int n, rb[2*mxN], rb_cnt, where[2*mxN];
vector<int> d, v[mxN], small, big;
bool seen[2*mxN];
vector<ar<int, 2>> oc[2*mxN];

void solve() {
	d.clear();
	cin >> n;
	for (int i=0; i<n; ++i) {
		int k;
		cin >> k;
		v[i].resize(k);
		for (int& j : v[i]) {
			cin >> j;
			d.push_back(j);
		}
		sort(v[i].begin(), v[i].end());
	}
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end())-d.begin());
	small.clear();
	big.clear();
	for (int i=0; i<n; ++i) {
		for (int& j : v[i])
			j=lower_bound(d.begin(), d.end(), j)-d.begin();
		if (v[i].size()<=B)
			small.push_back(i);
		else
			big.push_back(i);
	}
	for (int i=0; i<big.size(); ++i) {
		for (int j : v[big[i]])
			seen[j]=1;
		int found=-1;
		for (int j : small) {
			bool two=0;
			for (int x : v[j]) {
				if (two&&seen[x])
					found=j;
				two|=seen[x];
			}
			if (found!=-1)
				break;
		}
		for (int j=0; j<i&&found==-1; ++j) {
			bool two=0;
			for (int x : v[big[j]]) {
				if (two&&seen[x])
					found=big[j];
				two|=seen[x];
			}
		}
		for (int j : v[big[i]])
			seen[j]=0;
		if (found!=-1) {
			cout << big[i]+1 << " " << found+1 << "\n";
			return;
		}
	}
	for (int i : small)
		for (int j=0; j+1<v[i].size(); ++j) {
			if (oc[v[i][j]].empty())
				rb[rb_cnt++]=v[i][j];
			oc[v[i][j]].push_back({i, j+1});
		}
	ar<int, 2> ans={-1, -1};
	for (int i=0; i<rb_cnt&&ans[0]==-1; ++i) {
		for (auto [j, k] : oc[rb[i]]) {
			for (int l=k; l<v[j].size(); ++l) {
				if (where[v[j][l]]) {
					ans={where[v[j][l]], j+1};
					break;
				}
				where[v[j][l]]=j+1;
			}
			if (ans[0]!=-1)
				break;
		}
		for (auto [j, k] : oc[rb[i]])
			for (int l=k; l<v[j].size(); ++l)
				where[v[j][l]]=0;
	}
	for (int i=0; i<rb_cnt; ++i)
		oc[rb[i]].clear();
	rb_cnt=0;
	if (ans[0]==-1)
		cout << "-1\n";
	else
		cout << ans[0] << " " << ans[1] << "\n";
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