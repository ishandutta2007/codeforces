#include<cassert>
#include<deque>
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

int N, K, M;
int A[100111];

void task_same() {
    LL z = (LL)N * M;
    printf("%lld\n", z % K);
}

deque<pair<int, LL> > cat(deque<pair<int, LL> > x, const deque<pair<int, LL> > &y) {
    EACH (e, y) {
	if (x.size() && x.back().first == e->first) {
	    x.back().second += e->second;
	    x.back().second %= K;
	    if (x.back().second == 0) x.pop_back();
	} else {
	    x.push_back(*e);
	}
    }
    return x;
}

void task() {
    deque<pair<int, LL> > head, mid, tail;

    LL cnt = 1;
    int last = A[0];
    for (int i=1; i<N; i++) {
	if (A[i] != last) {
	    cnt %= K;
	    if (cnt) {
		if (!mid.empty() && mid.back().first == last) {
		    mid.back().second += cnt;
		    mid.back().second %= K;
		    if (mid.back().second==0) mid.pop_back();
		} else {
		    mid.push_back(make_pair(last, cnt));
		}
	    }
	    last = A[i];
	    cnt = 1;
	} else {
	    cnt++;
	}
    }

    cnt %= K;
    if (cnt) {
	if (!mid.empty() && mid.back().first == last) {
	    mid.back().second += cnt;
	    mid.back().second %= K;
	    if (mid.back().second==0) mid.pop_back();
	} else {
	    mid.push_back(make_pair(last, cnt));
	}
    }

    LL left = 0;

    if (M == 1) {
	EACH (e, mid) left += e->second;
    } else if (M == 2) {
	mid = cat(mid, mid);
	EACH (e, mid) left += e->second;
    } else {
	head = tail = mid;
	M -= 2;

	while (!head.empty()
		&& mid.size() >= 2u
		&& head.back().first == mid[0].first) {

	    assert(head.back().second == mid.back().second);
	    assert(mid[0].second == tail[0].second);
	    head.back().second += mid[0].second;
	    mid.back().second += tail[0].second;
	    mid.pop_front();
	    tail.pop_front();

	    head.back().second %= K;
	    mid.back().second %= K;

	    if (head.back().second == 0) {
		head.pop_back();
		mid.pop_back();
	    }
	}

	if (mid.size() <= 1u) {
	    if (mid.empty()) {
		head = cat(head, tail);
	    } else {
		mid.back().second = (LL)mid.back().second * M % K;
		head = cat(head, cat(mid, tail));
	    }
	    EACH (e, head) left += e->second;
	} else {
	    EACH (e, head) left += e->second;
	    EACH (e, mid) left += (LL)e->second * M;
	    EACH (e, tail) left += e->second;
	}
    }

    printf("%lld\n", left);
}

void MAIN() {
    scanf("%d%d%d", &N, &K, &M);
    REP (i, N) scanf("%d", A+i);

    bool same = true;
    REP (i, N-1) if (A[i] != A[i+1]) same = false;

    if (same) task_same();
    else task();
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}