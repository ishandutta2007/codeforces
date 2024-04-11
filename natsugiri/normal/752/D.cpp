#include<map>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N, L;
char buf[100111];

int A[100111];
map<string, pair<VI, VI> > M;
map<string, VI> S;

int main() {
    scanf("%d%d", &N, &L);
    REP (i, N) {
	scanf("%s%d", buf, A+i);
	string s = buf, r = s;
	reverse(r.begin(), r.end());
	int c = s.compare(r);
	if (c < 0) {
	    M[s].first.push_back(A[i]);
	} else if (0 < c) {
	    M[r].second.push_back(A[i]);
	} else {
	    S[s].push_back(A[i]);
	}
    }

    LL ans = 0;
    LL diff = 0;

    EACH (e, M) {
	VI a = e->second.first;
	VI b = e->second.second;
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());

	REP (i, min(a.size(), b.size())) {
	    if (a[i] + b[i] > 0) {
		ans += a[i] + b[i];
	    } else {
		break;
	    }
	}
    }

    EACH (e, S) {
	VI a = e->second;
	sort(a.rbegin(), a.rend());
	for (int i=0; i<(int)a.size(); i+=2) {
	    if (a[i] < 0) break;
	    if (i+1 < (int)a.size() && a[i+1] < 0) {
		if (a[i] + a[i+1] > 0) {
		    ans += a[i] + a[i+1];
		    amax(diff, (LL)-a[i+1]);
		} else {
		    amax(diff, (LL)a[i]);
		}
		break;
	    } 
	    if (i+1 == (int)a.size()) {
		amax(diff, (LL)a[i]);
		break;
	    }
	    ans += a[i] + a[i+1];
	}
    }

    printf("%lld\n", ans + diff);

    return 0;
}