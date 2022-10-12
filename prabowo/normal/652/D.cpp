#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int n;
struct Segment {
	int l, r;
	int idx;
	
	bool operator < (const Segment &other) const {
		if (l == other.l) return r > other.r;
		return l < other.l;
	}
} seg[N];
int ans[N];

int sum[N << 1];

void update (int x, int val) {
	for (int i=x; i<n<<1; i+=i&-i)
		sum[i] += val;
}

int query (int x) {
	int ret = 0;
	for (int i=x; i; i-=i&-i)
		ret += sum[i];
	return ret;
}

int main () {
	scanf ("%d", &n);
	
	vector <int> v;
	for (int i=0; i<n; i++) {
		scanf ("%d %d", &seg[i].l, &seg[i].r);
		v.push_back (seg[i].l); v.push_back (seg[i].r);
		seg[i].idx = i;
	}
	
	sort (v.begin(), v.end());
		
	for (int i=0; i<n; i++)
		seg[i].l = lower_bound (v.begin(), v.end(), seg[i].l) - v.begin(),
		seg[i].r = lower_bound (v.begin(), v.end(), seg[i].r) - v.begin();
		
	sort (seg, seg + n);	
	for (int i=0; i<n; i++) update (seg[i].r, 1);
	
	for (int i=0; i<n; i++) {
		ans[seg[i].idx] = query(seg[i].r - 1) - query(seg[i].l);
		update (seg[i].r, - 1);
	}
	
	for (int i=0; i<n; i++) 
		printf ("%d\n", ans[i]);
	
	return 0;
}