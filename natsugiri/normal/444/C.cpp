#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<cassert>
using namespace std;

typedef long long LL;

struct SegmentTree {
    typedef long long T;
    int n, m;
    vector<T>all, part;
    vector<int> color;
    SegmentTree(int n) :n(n) {
	m=1;
	for (;m<n;) m*=2;
	all=part=vector<T>(m*2);
        color = vector<int>(m*2);
        for (int i=0; i<n; i++) color[i+m] = i+1;
        for (int i=m; --i;) color[i] = -1;
    }
    void paint(int x, int y, T v) { paint(x, y, 1, 0, m, v); }
    T paint(int x, int y, int k, int l, int r, T v) {
        assert(k < 2*m);
	if (x<=l && r<=y && color[k] != -1) {
            LL tmp = abs(v - (LL)color[k]);
            all[k] += tmp;
            color[k] = v;
	    return (r-l)*tmp;
	} else if (x<r && l<y) {
            if (color[k] != -1) color[k*2] = color[k*2+1] = color[k];
            color[k] = -1;
            T tmp = 0;
	    tmp += paint(x, y, k*2, l, (l+r)/2, v);
	    tmp += paint(x, y, k*2+1, (l+r)/2, r, v);
	    part[k] += tmp;
            if (x<=l && r<=y) color[k] = v;
            return tmp;
	} else {
            return 0;
        }
    }
    T sum(int x, int y) { return sum(x, y, 1, 0, m); }
    T sum(int x, int y, int k, int l, int r) {
	if (r<=x || y<=l) return 0;
	if (x<=l && r<=y) return (r-l)*all[k]+part[k];
	return (min(y, r)-max(x, l))*all[k]
	    + sum(x, y, k*2, l, (l+r)/2)
	    + sum(x, y, k*2+1, (l+r)/2, r);
    }
};
int main() {
    int N, M;
    int type, l, r, x;
    scanf("%d%d", &N, &M);
    SegmentTree R(N);
    for (;M--;) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d%d%d", &l, &r, &x);
            l--;
            R.paint(l, r, x);
        } else {
            scanf("%d%d", &l, &r);
            l--;
            printf("%lld\n", R.sum(l, r));
        }
    }
        
    return 0;
}