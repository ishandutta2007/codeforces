#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int n;
int s[303030];
int t[303030];
vector<pair<int,int>> vs, vt;
deque<pair<int,int>> va, vb;
int cc[303030];

void rip() {
	cout << "NO\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++) cin >> t[i];
	for (int i = 0; i < n; i++) {
		vs.push_back({s[i],i});
		vt.push_back({t[i],i});
	}
	sort(vs.begin(),vs.end());
	sort(vt.begin(),vt.end());
	for (int i = 0; i < n; i++) {
		cc[vs[i].second] = abs(vs[i].first-vt[i].first);
		if (vs[i].first == vt[i].first) continue;
		if (vs[i].first < vt[i].first) {
			va.push_back(vs[i]);
		} else {
			vb.push_back(vs[i]);
		}
	}
	sort(t,t+n);
	vector<vector<int>> rr;
	while (true) {
		while (va.size() && cc[va[0].second] == 0) va.pop_front();
		while (vb.size() && cc[vb[0].second] == 0) vb.pop_front();
		if (!va.size() && !vb.size()) break;
		if (va.size() && vb.size()) {
			int x = va[0].second;
			int y = vb[0].second;
			if (s[x] >= s[y]) rip();
			int d = min(cc[x],cc[y]);
			if (2*d > s[y]-s[x]) rip();
			s[x] += d;
			s[y] -= d;
			cc[x] -= d;
			cc[y] -= d;
			rr.push_back({x+1,y+1,d});
		} else {
			rip();
		}
	}
	cout << "YES\n";
	cout << rr.size() << "\n";
	for (auto x : rr) {
		cout << x[0] << " " << x[1] << " " << x[2] << "\n";
	}
}