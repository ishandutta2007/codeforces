#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

struct Node {int x, y;} o[4];
struct T {int t1, t2, t3, t4;};

int main() {
	int mnx = 1e9 + 10, mxx = -1e9 - 10;
	int mny = 1e9 + 10, mxy = -1e9 - 10;
	vector<int> vx, vy;
	for (int i = 1; i <= 3; i++) {
		cin >> o[i].x >> o[i].y;
		vx.push_back(o[i].x);
		vy.push_back(o[i].y);
		mnx = min(mnx, o[i].x);
		mxx = max(mxx, o[i].x);
		mny = min(mny, o[i].y);
		mxy = max(mxy, o[i].y);
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	vector<T> ans;
	for (int i = 1; i <= 3; i++) {
		if (o[i].x == mnx && o[i].x != vx[1])
			ans.push_back((T){o[i].x, o[i].y, vx[1], o[i].y});
		if (o[i].x == mxx && o[i].x != vx[1])
			ans.push_back((T){o[i].x, o[i].y, vx[1], o[i].y});
	}
	if (mxy != mny) ans.push_back((T){vx[1], mny, vx[1], mxy});
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].t1 << " " << ans[i].t2 << " " << ans[i].t3 << " " << ans[i].t4 << endl;
	return 0;
}