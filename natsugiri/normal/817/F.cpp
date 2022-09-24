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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using Set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//template<class T, class U> using Map = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
   iterator find_by_order(size_t);
   const_iterator find_by_order(size_t) const;
   size_t order_of_key(const T) const;
*/


void MAIN() {
    int Q;
    scanf("%d", &Q);
    Set<LL> S;
    S.insert(1LL<<60);
    S.insert((1LL<<60) + 1);

    REP ($, Q) {
	char op[11];
	LL L, R;
	scanf("%s%lld%lld", op, &L, &R);
	R++;
	if (*op == '1') {
	    auto it = S.lower_bound(L);
	    int cnt = 0;
	    while (it != S.end() && *it <= R) {
		S.erase(it++);
		cnt++;
	    }
	    int k = S.order_of_key(L);
	    if (k % 2 == 0) {
		S.insert(L);
	    }
	    if (S.size() % 2) S.insert(R);

	} else if (*op == '2') {
	    auto it = S.lower_bound(L);
	    int cnt = 0;
	    while (it != S.end() && *it <= R) {
		S.erase(it++);
		cnt++;
	    }
	    int k = S.order_of_key(L);
	    if (k % 2 == 1) {
		S.insert(L);
	    }
	    if (S.size() % 2) S.insert(R);
	    
	} else if (*op == '3') {
	    auto it = S.lower_bound(L);
	    if (it != S.end() && *it == L) S.erase(it);
	    else S.insert(L);

	    it = S.lower_bound(R);
	    if (it != S.end() && *it == R) S.erase(it);
	    else S.insert(R);
	}

	LL ans;
	if (S.empty()) ans = 1;
	else if (*S.begin() > 1) ans = 1;
	else ans = *S.find_by_order(1);


	printf("%lld\n", ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}