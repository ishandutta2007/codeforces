#include<cassert>
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
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }



int N, M;
int X_origin[200011];
pair<LL, int> X[200011];

int LE(LL p) {
    return lower_bound(X, X+N, make_pair(p+1, -1)) - X - 1;
}
int GE(LL p) {
    return lower_bound(X, X+N, make_pair(p, -1)) - X;
}

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", X_origin+i);
    REP (i, N) X[i] = make_pair(X_origin[i], i);
    sort(X, X+N);

    REP ($, M) {
	int s; LL len;
	scanf("%d%lld", &s, &len);

	if (N == 1) {
	    puts("1");
	    continue;
	}
	
	s = GE(X_origin[s-1]);

	bool right = true;
	int ans = -1;
	REP (tt, 40) {
	    if (tt == 999) assert(false);
	    int t;
	    if (right) { // s -> t
		t = LE(X[s].first + len); // LOG n
		if (s == t) {
		    ans = X[s].second;
		    right = false;
		    continue;
		}
		assert(s < t);
		
		LL W = X[t].first - X[s].first;

		if (tt > 20) {
		    len %= 2*W;
		    if (len >= W) {
			right = false;
			len -= W;
			s = t;
		    }
		} else {
		    right = false;
		    len -= W;
		    s = t;
		}
	    } else { // t <- s
		t = GE(X[s].first - len);
		if (s == t) {
		    ans = X[s].second;
		    right = true;
		    continue;
		}
		assert(t < s);

		LL W = X[s].first - X[t].first;
		if (tt > 20) {
		    len %= 2*W;
		    if (len >= W) {
			right = true;
			len -= W;
			s = t;
		    }
		} else {
		    right = true;
		    len -= W;
		    s = t;
		}
	    }
	}

	printf("%d\n", ans+1);
    }
    return 0;
}