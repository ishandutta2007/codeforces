#include<deque>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, T b) { if (a<b) a=b; }

struct Task {
    int x, y, i;
    bool operator<(const Task &b) const {
	return x < b.x;
    }
};

int N, Q;
LL P[200011], L[200011], ans[200011];
Task Z[200011];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld%lld", P+i, L+i);
    scanf("%d", &Q);
    REP (i, Q) {
	scanf("%d%d", &Z[i].x, &Z[i].y);
	Z[i].x--; Z[i].y--;
	Z[i].i = i;
    }
    sort(Z, Z+Q);

    deque<int> left;
    LL off = 0;
    deque<LL>right, sums;
    
    for (int i=Q, idx=N; i--;) {
	int x = Z[i].x, y = Z[i].y;
	while (x < idx) {
	    idx--;
	    LL ri = P[idx]+L[idx];
	    while (left.size() && ri >= P[left[0]]) {
		amax(ri, right[0]);
		right.pop_front();
		left.pop_front();
		sums.pop_front();
		off = (sums.size() ? -sums[0] : 0LL);
	    }

	    LL o = (left.size() ? P[left[0]] - ri : 0LL);
	    off += o;
	    // cerr << o << ' ' << off << '\n';
	    sums.push_front(-off);
	    right.push_front(ri);
	    left.push_front(idx);

	    // cerr << "#\n";
	    // REP (p, left.size()) {
	    // 	cerr << left[p] << ' ' << right[p] << ' '<< off+sums[p] << '\n';
	    // }
	    // cerr << '\n';
	}

	int lo = 0, hi = left.size();
	while (hi-lo>1) {
	    int m = (lo+hi)/2;
	    if (P[x]+L[x] >= P[left[m]]) lo = m;
	    else hi = m;
	}

	int be = lo;
	int en = upper_bound(left.begin(), left.end(), y) - left.begin();
	if (en) en--;

	ans[Z[i].i] = max(0LL, sums[en] - sums[be]);
    }


    REP (i, Q) printf("%lld\n", ans[i]);
    return 0;
}