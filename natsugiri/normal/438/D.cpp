#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const LL INF = 1LL<<60;

struct SegmentTree {
    int n, m;
    vector<LL> maxi, all;
    vector<int> maxi_i;
    SegmentTree(int n) : n(n) {
	m = 1;
	for (; m<n; ) m*=2;
	maxi = all = vector<LL>(2*m, 0);
	maxi_i = vector<int>(2*m, -1);
    }
    void update(int k, LL v) {
	k += m;
	maxi[k] = v;
	maxi_i[k] = k-m;
	all[k] = v;
	while (k>1) {
	    k /= 2;
	    if (maxi[k*2] >= maxi[k*2+1]) {
		maxi[k] = maxi[k*2];
		maxi_i[k] = maxi_i[k*2];
	    } else {
		maxi[k] = maxi[k*2+1];
		maxi_i[k] = maxi_i[k*2+1];
	    }
	    all[k] = all[k*2]+all[k*2+1];
	}
    }
    pair<LL, int> maximum(int x, int y) { return maximum(x, y, 1, 0, m); }
    pair<LL, int> maximum(int x, int y, int k, int l, int r) {
	if (x<=l && r<=y) return make_pair(maxi[k], maxi_i[k]);
	if (r<=x || y<=l) return make_pair<LL, int>(-INF, -1);
	return max(maximum(x, y, k*2, l, (l+r)/2), maximum(x, y, k*2+1, (l+r)/2, r));
    }
    LL sum(int x, int y) { return sum(x, y, 1, 0, m); }
    LL sum(int x, int y, int k, int l, int r) {
	if (x<=l && r<=y) return all[k];
	if (r<=x || y<=l) return 0;
	return sum(x, y, k*2, l, (l+r)/2) + sum(x, y, k*2+1, (l+r)/2, r);
    }

};

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    SegmentTree st(N);
    for (int i=0; i<N; i++) {
	int a;
	scanf("%d", &a);
	st.update(i, a);
    }

    for (;M--;) {
	int tp;; scanf("%d", &tp);
//	for (int i=0; i<N; i++) cout << st.all[i+st.m] << " "; cout << endl;
	if (tp == 1) {
	    int l, r;
	    scanf("%d%d", &l, &r);
	    l--;
	    printf("%lld\n", st.sum(l, r));
	} else if (tp == 2) {
	    int l, r;
	    LL x;
	    scanf("%d%d%lld", &l, &r, &x);
	    l--;
	    while (true) {
		pair<LL, int> p = st.maximum(l, r);
		if (p.first < x) break;
		st.update(p.second, p.first%x);
	    }
	} else {
	    int k;
	    LL x;
	    scanf("%d%lld", &k, &x);
	    k--;
	    st.update(k, x);
	}
    }
    return 0;
}