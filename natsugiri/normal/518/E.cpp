#include<cstdio>
#include<iostream>
#include<sstream>
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
template<class T>
T str2T(const string&s) {
    stringstream ss(s);
    T n;
    ss >> n;
    return n;
}

const LL INF = 1LL<<40;
int N, K;
bool H[100011];
int A[100011];
char buf[9999];

bool ok;

void calc(const VI &v, LL lo, LL hi) {
    int cnt = v.size();
    if (cnt == 0) return;

    if (hi - lo - 1 < cnt) { ok = false; return ; }

    if (lo < -(cnt-1)/2 && cnt/2 < hi) {
	int x = -(cnt-1)/2;
	for (int i=0; i<cnt; i++, x++) {
	    A[v[i]] = x;
	}
    } else if (abs(lo) < abs(hi)) {
	REP (i, cnt) A[v[i]] = lo + 1 + i;
    } else {
	REP (i, cnt) A[v[i]] = hi - (cnt-i);
    }
}

int main() {
    scanf("%d%d", &N, &K);
    REP (i, N) {
	scanf("%s", buf);
	if (buf[0] == '?') H[i] = true;
	else A[i] = str2T<int>(string(buf));
    }

    ok = true;

    REP (i, min(K, N)) {
	VI v;
	LL low = -INF;
	for (int j=i; j<N; j+=K) {
	    if (H[j]) {
		v.push_back(j);
	    } else {
		calc(v, low, A[j]);
		low = A[j];
		v.clear();
	    }
	}

	calc(v, low, INF);
    }

    REP (i, min(K, N)) {
	for (int j=i; j+K<N; j+=K)
	    if (A[j] >= A[j+K]) ok = false;
    }
    
    if (ok) {
	REP (i, N) printf("%d%c", A[i], i+1==N? '\n': ' ');
    } else {
	puts("Incorrect sequence");
    }
    
    return 0;
}