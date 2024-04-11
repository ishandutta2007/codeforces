#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n;
ar<int, 2> cnt[mxN];

ar<int, 2> ck(int x) {
	int lx=0, rx=69696969, ly=0, ry=69696969, ls=-69696969, rs=69696969;
	for (int i=0; i<n; ++i) {
		lx=max(lx, cnt[i][0]-x);
		rx=min(rx, cnt[i][0]+x);
		ly=max(ly, cnt[i][1]-x);
		ry=min(ry, cnt[i][1]+x);
		ls=max(ls, cnt[i][1]-cnt[i][0]-x);
		rs=min(rs, cnt[i][1]-cnt[i][0]+x);
	}
	//cout << lx << " " << rx << " " << ly << " " << ry << " " << ls << " " << rs << endl;
	if (lx>rx||ly>ry||ls>rs)
		return {-1, -1};
	for (int line : {ls, rs}) { // y=x+line
		if (ly<=lx+line&&lx+line<=ry)
			return {lx, lx+line};
		if (lx<=ly-line&&ly-line<=rx)
			return {ly-line, ly};
	}
	if (lx+rs>ry&&rx+ls<ly)
		return {lx, ly};
	return {-1, -1};
}

int cmp(int x, int y) {
	int mx=0;
	for (int i=0; i<n; ++i) {
		if (cnt[i][0]>=x&&cnt[i][1]>=y||cnt[i][0]<=x&&cnt[i][1]<=y)
			mx=max(mx, max(abs(x-cnt[i][0]), abs(y-cnt[i][1])));
		else
			mx=max(mx, abs(x-cnt[i][0])+abs(y-cnt[i][1]));
	}
	return mx;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		string s;
		cin >> s;
		for (char c : s)
			++cnt[i][c=='N'];
	}
	int lb=0, rb=5e5;
	while(lb<rb) {
		int mid=(lb+rb)/2;
		if (ck(mid)[0]!=-1)
			rb=mid;
		else
			lb=mid+1;
	}
	ar<int, 2> ans=ck(lb);
	assert(ans[0]!=-1);
	if (!ans[0]&&!ans[1]) {
		auto Ck=[&](int x, int y) {
			int k=cmp(x, y);
			assert(k>=lb);
			if (k==lb)
				ans={x, y};
		};
		Ck(1, 0);
		Ck(0, 1);
		Ck(1, 1);
	}
	assert(ans[0]||ans[1]);
	cout << lb << "\n" << string(ans[0], 'B') << string(ans[1], 'N');
	return 0;
}