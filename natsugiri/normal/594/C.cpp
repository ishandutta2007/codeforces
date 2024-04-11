#include<set>
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

int N, K;
pair<LL, int> xl[15], xh[15], yl[15], yh[15];
const LL INF = 1LL<<60;

VI xle, xhe, yle, yhe;
set<int> erased;
void ERASE(pair<LL, int> *X, int t, VI &v) {
    REP (i, K+1) {
	if (t == 0) break;
	if (erased.count(X[i].second) == 0) {
	    erased.insert(X[i].second);
	    v.push_back(X[i].second);
	    t--;
	}
    }
}

void PUT(VI &v) {
    EACH (e, v) {
	erased.erase(*e);
    }
    v.clear();
}

LL GET(pair<LL, int> *X) {
    REP (i, K+1) {
	if (erased.count(X[i].second) == 0) {
	    return X[i].first;
	}
    }
    assert(false);
}

int main() {
    scanf("%d%d", &N, &K);
    REP (i, K+2) {
	xl[i] = make_pair(INF, N);
	xh[i] = make_pair(-INF, N);
	yl[i] = make_pair(INF, N);
	yh[i] = make_pair(-INF, N);
    }
    
    REP (i, N) {
	LL x1, y1, x2, y2;
	scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
	LL x = x1+x2;
	LL y = y1+y2;

	xl[K+1] = xh[K+1] = make_pair(x, i);
	yl[K+1] = yh[K+1] = make_pair(y, i);
	sort(xl, xl+K+2);
	sort(xh, xh+K+2); reverse(xh, xh+K+2);
	sort(yl, yl+K+2);
	sort(yh, yh+K+2); reverse(yh, yh+K+2);
    }
    
    
    
    LL ans = INF;

    REP (xli, K+1) {
	ERASE(xl, xli, xle);
	
	REP (xhi, K+1-xli) {
	    ERASE(xh, xhi, xhe);
	    
	    REP (yli, K+1-xli-xhi) {
		ERASE(yl, yli, yle);
		
		REP (yhi, K+1-xli-xhi-yli) {
		    ERASE(yh, yhi, yhe);

		    // eprintf("%d %d %d %d %d\n", xli, xhi, yli, yhi, (int)erased.size());

		    LL xw = GET(xh) - GET(xl);
		    LL yw = GET(yh) - GET(yl);
		    if (xw <= 0) xw = 2;
		    if (xw & 1) xw++;
		    xw/=2;
		    if (yw <= 0) yw = 2;
		    if (yw & 1) yw++;
		    yw/=2;
		    amin(ans, xw * yw);
		    
		    PUT(yhe);
		}
		PUT(yle);
	    }
	    PUT(xhe);
	}
	PUT(xle);
    }


    printf("%lld\n", ans);
    return 0;
}