#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5000, M=1e9+7;
int n, m, a[mxN], cnt1[mxN], cnt2[mxN];
vector<int> pref[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> a[i], --a[i];
		++cnt2[a[i]];
	}
	for (int i=0; i<n; ++i)
		pref[i].resize(cnt2[i]+1);
	for (int i=0; i<m; ++i) {
		int x, y;
		cin >> x >> y, --x;
		if (y<=cnt2[x])
			++pref[x][y];
	}
	for (int i=0; i<n; ++i)
		for (int j=1; j<=cnt2[i]; ++j)
			pref[i][j]+=pref[i][j-1];
	ll cur=0, cur_cnt=1;
	for (int i=0; i<n; ++i)
		if (pref[i][cnt2[i]]) {
			++cur;
			cur_cnt=cur_cnt*pref[i][cnt2[i]]%M;
		}
	ll ans=cur, ans_cnt=cur_cnt;
	for (int i=0; i<n; ++i) {
		++cnt1[a[i]], --cnt2[a[i]];
		if (pref[a[i]][cnt1[a[i]]]==pref[a[i]][cnt1[a[i]]-1])
			continue;
		cur=1, cur_cnt=1;
		if (pref[a[i]][cnt2[a[i]]]-(cnt2[a[i]]>=cnt1[a[i]])) {
			++cur;
			cur_cnt=pref[a[i]][cnt2[a[i]]]-(cnt2[a[i]]>=cnt1[a[i]]);
		}
		//cout << cur << " " << cur_cnt << " " << pref[a[i]][cnt2[i]] << endl;
		for (int j=0; j<n; ++j) {
			if (j!=a[i]) {
				int x=pref[j][cnt1[j]], y=pref[j][cnt2[j]];
				int c2=x*y-min(x, y);
				if (c2) {
					cur+=2;
					cur_cnt=cur_cnt*c2%M;
				} else if (x+y) {
					++cur;
					cur_cnt=cur_cnt*(x+y)%M;
				}
			}
		}
		if (cur>ans)
			ans=cur, ans_cnt=cur_cnt;
		else if (cur==ans)
			ans_cnt=(ans_cnt+cur_cnt)%M;
		//cout << i << " " << ans << " " << ans_cnt << endl;
	}
	cout << ans << " " << ans_cnt;
	return 0;
}