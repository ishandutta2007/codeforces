#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
char S[100011];

int Len[100011];
string ans[100011];

void MAIN() {
    scanf("%s", S);
    N = strlen(S);

    vector<pair<char, int> > stk;
    pair<char, int> head('$', 1);
    int len = 0;

    auto get = [&](char except) {
	for (int i=stk.size(); i--;) if (stk[i].first != except) {
	    return stk[i].first;
	}

	return '\0';
    };



    for (int i=N; i--;) {
	char c = S[i];
	if (len == 0 || head.first != c) {
	    len++;
	    if (head.first != '$') stk.push_back(head);
	    head = make_pair(c, 1);
	} else if (len == 1 || get(c) < c) {
	    head.second--;
	    len--;
	    if (head.second == 0) head = make_pair('$', 1);
	} else {
	    len++;
	    head.second++;
	}

	Len[i] = len;

	if (head.first != '$') {
	    stk.push_back(head);
	}

	if (len > 10) {
	    for (int k=stk.size(); k--;) REP (t, stk[k].second) {
		ans[i].push_back(stk[k].first);
		if (ans[i].size() == 5u) goto OUT1;
	    }
OUT1:

	    REP (t, 3) ans[i].push_back('.');

	    REP (k, stk.size()) REP (t, stk[k].second) {
		ans[i].push_back(stk[k].first);
		if (ans[i].size() == 10u) goto OUT2;
	    }
OUT2:
	    
	    swap(ans[i][8], ans[i][9]);
	} else {
	    REP (k, stk.size()) REP (t, stk[k].second)
		ans[i].push_back(stk[k].first);
	    reverse(ans[i].begin(), ans[i].end());
	}

	if (head.first != '$') {
	    stk.pop_back();
	}
    }

    REP (i, N) printf("%d %s\n", Len[i], ans[i].c_str());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}