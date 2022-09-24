#include<queue>
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

string E[1<<8];
string T[1<<8];
string F[1<<8];

int C[1<<8];
int cnt = 0;

bool update(string &x, const string &y) {
    if (x.empty() || x.size() > y.size() || (x.size() == y.size() && x > y)) {
	x = y;
	return true;
    }
    return false;
}

priority_queue<pair<int, int> > Q;
void check(string &x, const string &y, int s) {
    if (update(x, y) && C[s] != cnt) {
	Q.emplace(-x.size(), s);
	C[s] = cnt;
    }
}

void init() {
    F[0xF0] = "x";
    F[0xCC] = "y";
    F[0xAA] = "z";
    Q.emplace(-1, 0xF0);
    Q.emplace(-1, 0xCC);
    Q.emplace(-1, 0xAA);

    while (!Q.empty()) {
	//int len = -Q.top().first;
	int a = Q.top().second;

	cnt++;
	Q.pop();

	if (!F[a].empty()) check(T[a], F[a], a);
	if (!T[a].empty()) check(E[a], T[a], a);
	if (!E[a].empty()) check(F[a], string(1, '(') + E[a] + string(1, ')'), a);

	if (!F[a].empty()) {
	    int s = a ^ 0xFF;
	    check(F[s], string(1, '!') + F[a], s);
	}

	REP (b, 1<<8) {
	    int s;
	    s = a & b;
	    if (!T[a].empty() && !F[b].empty()) check(T[s], T[a] + "&" + F[b], s);
	    if (!T[b].empty() && !F[a].empty()) check(T[s], T[b] + "&" + F[a], s);

	    s = a | b;
	    if (!E[a].empty() && !T[b].empty()) check(E[s], E[a] + "|" + T[b], s);
	    if (!E[b].empty() && !T[a].empty()) check(E[s], E[b] + "|" + T[a], s);
	}
    }
}

void MAIN() {
    char buf[11];
    scanf("%s", buf);
    int k = 0;
    REP (i, 8) if (buf[i] == '1') k |= 1<<i;
    printf("%s\n", E[k].c_str());
}

int main() {
    init();
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();

#ifdef LOCAL
    REP (i, 1<<8) cerr << E[i] << endl;
#endif
    return 0;
}