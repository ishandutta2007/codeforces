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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int N;
int C[10], D[10];
char sub[1000111];

string type1() {
    if (sub[0] == '0') return "{}";
    string S = sub;
    REP (i, 10) REP (j, C[i]) S.push_back(i + '0');
    return S;
}

string type2() {
    int p = 11;
    for (int i=1; i<10; i++) if (C[i]) amin(p, i);
    string S;
    if (p < 10) {
	S = string(1, p+'0');
	C[p]--;
    }
    REP (i, 10) {
	if (sub[0] - '0' == i) S += sub;
	REP (j, C[i]) S.push_back(i + '0');
    }
    if (p < 10) {
	C[p]++;
    }

    if (S[0] == '0') S = "{}";
    return S;
}
string type3() {
    int p = 11;
    for (int i=1; i<10; i++) if (C[i]) amin(p, i);
    string S;
    if (p < 10) {
	S = string(1, p+'0');
	C[p]--;
    }

    REP (i, 10) {
	REP (j, C[i]) S.push_back(i + '0');
	if (sub[0] - '0' == i) S += sub;
    }
    if (p < 10) {
	C[p]++;
    }
    if (S[0] == '0') S = "{}";
    return S;
}



int main() {
    scanf("%s", sub);
    N = strlen(sub);
    REP (i, strlen(sub)) C[sub[i] - '0']++;
    scanf("%s", sub);
    REP (i, strlen(sub)) {
	D[sub[i] - '0']++;
	C[sub[i] - '0']--;
    }


    int L = max(1, N-100);
    for (;; L++) {
	int m = L;
	while (m) {
	    C[m%10]--;
	    m/=10;
	    N--;
	}
	if (N == L && 0 <= *min_element(C, C+10)) break;
	m = L;
	while (m) {
	    C[m%10]++;
	    m/=10;
	    N++;
	}
    }


    string ans;
    if (L == 1 && D[0] == 1) {
	ans = "0";
    } else {
	ans = min(type1(), min(type2(), type3()));
    }


    printf("%s\n", ans.c_str());
    return 0;
}