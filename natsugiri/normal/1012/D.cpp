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

int find_last(const string &s, int cnt) {
    if (cnt == 0) return s.size();
    int d = 0;
    for (int i=(int)s.size()-2; i>=0; i--) {
	if (s[i] != s[i+1]) d++;
	if (d == cnt) return i+1;
    }

    return 0;
}

vector<pair<int, int> > solve(string S, string T, int add) {
    if (S.back() != 'a') S.push_back('a');
    if (T.back() != 'b') T.push_back('b');

    int cntS = 1;
    REP (i, (int)S.size()-1) if (S[i] != S[i+1]) cntS++;
    int cntT = 1;
    REP (i, (int)T.size()-1) if (T[i] != T[i+1]) cntT++;

    vector<pair<int, int> > ans;
    if (cntS + 2 < cntT) {
	int d = (cntT - cntS) / 2 + add;
	if (d%2==0) d++;
	int posT = find_last(T, d);
	int posS = find_last(S, 1);

	ans.emplace_back(posS, posT);
	string tmp = S.substr(0, posS);
	S = T.substr(0, posT) + S.substr(posS);
	T = tmp + T.substr(posT);

    } else if (cntS > cntT + 2) {
	int d = (cntS - cntT) / 2 + add;
	if (d%2==0) d++;
	int posS = find_last(S, d);
	int posT = find_last(T, 1);

	ans.emplace_back(posS, posT);
	string tmp = S.substr(0, posS);
	S = T.substr(0, posT) + S.substr(posS);
	T = tmp + T.substr(posT);
    }

    while (1) {
	while (!S.empty() && S.back() == 'a') S.pop_back();
	while (!T.empty() && T.back() == 'b') T.pop_back();
	if (S.empty() && T.empty()) return ans;
	ans.emplace_back(S.size(), T.size());
	swap(S, T);
    }
}

int N;
char buf[500111];
string S, T;

void MAIN() {
    scanf("%s", buf);
    S = buf;
    scanf("%s", buf);
    T = buf;

    if (count(S.begin(), S.end(), 'a') == 0 && count(T.begin(), T.end(), 'b') == 0) {
	puts("0");
	return;
    }
    if (count(S.begin(), S.end(), 'b') == 0 && count(T.begin(), T.end(), 'a') == 0) {
	puts("0");
	return;
    }


    vector<pair<int, int> > ans, tmp;

    REP (a, 2) REP (b, 2) {
	if (a) {
	    tmp = solve(S, T, b);
	} else {
	    tmp = solve(T, S, b);
	    EACH (e, tmp) swap(e->first, e->second);
	}
	if (ans.empty() || ans.size() > tmp.size()) ans = tmp;
    }

    printf("%d\n", (int)ans.size());
    EACH (e, ans) printf("%d %d\n", e->first, e->second);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}