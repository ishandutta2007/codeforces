#include <cstdio>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>

typedef long long LL;
const int N = 100000;

std :: pair <LL, int> volume[N];

struct SegmentTree {
	LL maks[N << 2];
	
	void update (int node, int l, int r, int x, LL val) {
		if (l > x || r < x) return;
		if (l == x && r == x) {
			maks[node] = val;
			return;
		}
		
		int mid = l + r >> 1;
		update (2 * node + 1, l, mid + 0, x, val);
		update (2 * node + 2, mid + 1, r, x, val);
		maks[node] = std :: max (maks[2 * node + 1], maks[2 * node + 2]);
		return;
	}
	
	LL query (int node, int l, int r, int b) {
		if (l > b) return 0;
		if (r <= b) return maks[node];
		
		int mid = l + r >> 1;
		return std :: max (query (2 * node + 1, l, mid, b), query (2 * node + 2, mid + 1, r, b));
	}
	
} segmentTree;

int main () {
	int n;
	scanf ("%d", &n);
	
	int r, h;
	for (int i=0; i<n; i++) {
		scanf ("%d %d", &r, &h);
		volume[i].first = (LL) r * r * h;
		volume[i].second = i;
	}
	
	std :: sort (volume, volume + n);
	
	LL ans = 0;
	for (int i=0; i<n;) {		
		std :: vector < std :: pair <int, LL> > update;
		LL now = volume[i].first;
		
		while (i < n && volume[i].first == now) {
			LL val = volume[i].first + segmentTree.query (0, 0, n - 1, volume[i].second - 1);
			ans = std :: max(ans, val);
			update.push_back ( std :: make_pair (volume[i].second, val) );
			i++;
		}		
		
		while (update.size()) {
			segmentTree.update (0, 0, n - 1, update.back().first, update.back().second);
			update.pop_back();
		}
	}
	
	printf ("%.9lf\n", ans * acos(-1));
	return 0;
}