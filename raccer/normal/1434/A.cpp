#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

vector <int> node[100010];
vector <pii> all;
int cur[100010], a[100010], b[100010];
multiset <int> S;

int main () {
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}
	int n; cin >> n;
	int minj = 0x3f3f3f3f, maxj = -1;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		for (int j = 0; j < 6; j++) {
			all.push_back(mp(b[i] - a[j], i));
			node[i].push_back(b[i] - a[j]);
		}
		sort(node[i].begin(), node[i].end());
		cur[i] = 0, S.insert(node[i][0]);
	}
	sort(all.begin(), all.end());
	int ans = *(--S.end()) - *S.begin();
	for (int i = 0; i < all.size(); i++) {
		int x = all[i].se;
		S.erase(S.find(node[x][cur[x]]));
		cur[x]++;
		if (cur[x] == 6) break;
		S.insert(node[x][cur[x]]);
		ans = min(ans, *(--S.end()) - *S.begin());
	}
	cout << ans << endl;
	return 0;
}