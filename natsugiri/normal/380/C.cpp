#include<stack>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const LL INF = 1LL<<61;

struct SegmentTree {
    int n, m;
    vector<int>left, right;
    SegmentTree(string &S) :n(S.size()) {
        m=1;
        for (;m<n;) m*=2;
	left = right = vector<int>(m*2);
	for (int i=0; i<n; i++) {
	    if (S[i] == '(') left[i+m]++;
	    else right[i+m]++;
	}
	for (int i=m; --i; ) {
	    pair<int,int> p = add(left[i*2], right[i*2], left[i*2+1], right[i*2+1]);
	    left[i] = p.first;
	    right[i] = p.second;
	}
    }
    pair<int,int> add(int l0, int r0, int l1, int r1) {
	pair<int,int> p;
	int g = min(l0, r1);
	p.first = l0+l1-g;
	p.second = r0+r1-g;
	return p;
    }
    
    pair<int,int> query(int x, int y) { return query(x, y, 1, 0, m); }
    pair<int,int> query(int x, int y, int k, int l, int r) {
        if (r<=x || y<=l) return make_pair(0, 0);
        if (x<=l && r<=y) return make_pair(left[k], right[k]);
	pair<int,int> a = query(x, y, k*2, l, (l+r)/2),
	    b = query(x, y, k*2+1, (l+r)/2, r);
	return add(a.first, a.second, b.first, b.second);
    }
};

int main() {
    string S;
    cin >> S;
    int N = S.size();

    SegmentTree st(S);

    int M;
    scanf("%d", &M);
    for (;M--;) {
	int l, r;
	scanf("%d%d", &l, &r);
	l--;
	pair<int,int> p = st.query(l, r);
//	printf("%d %d\n", p.first, p.second);
	printf("%d\n", r-l-p.first-p.second);
    }
	    
    return 0;
}