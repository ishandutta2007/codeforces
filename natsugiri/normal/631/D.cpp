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

typedef pair<LL, char> Pair;

struct KMP {
    vector<int>fail;
    vector<Pair> p;
    KMP(){}
    KMP(const vector<Pair>&p) :p(p) {
	int m=p.size();
	fail = vector<int>(m+1);
	int j = fail[0] = -1;
	for (int i=1; i<=m; i++) {
	    while (j>=0 && p[j] != p[i-1]) j = fail[j];
	    fail[i] = ++j;
	}
    }
    vector<int> match(const vector<Pair> &t) {
	int n=t.size(), m=p.size();
	vector<int>ret;
	for (int i=0, k=0; i<n; i++) {
	    while (k>=0 && p[k] != t[i]) k=fail[k];
	    if (++k >= m) {
		ret.push_back(i); // match at t[i-m+1 .. i]
		k = fail[k];
	    }
	}
	return ret;
    }
};

int N, M;
vector<Pair> S, T, U;

void get(int N, vector<Pair> &S) {
    int l; char c[9];
    REP (i, N) {
	scanf("%d-%s", &l, c);
	if (S.size() && S.back().second == c[0]) S.back().first += l;
	else S.push_back(Pair(l, c[0]));
    }
}
bool in(const Pair &x, const Pair &y) {
    return x.second == y.second && x.first <= y.first;
}

int main() {
    scanf("%d%d", &N, &M);
    get(N, S);
    get(M, T);

    N = S.size();
    M = T.size();


    LL ans = 0;
    if (M == 1) {
	EACH (e, S) {
	    if (in(T[0], *e))
		ans += e->first - T[0].first + 1;
	}
    } else if (M == 2) {
	REP (i, N-1) {
	    if (in(T[0], S[i]) && in(T[1], S[i+1])) ans++;
	}
    } else {
	U.assign(T.begin()+1, T.end()-1);
	KMP kmp(U);
	VI v = kmp.match(S);
	EACH (e, v) {
	    int l = *e-(M-2)+1;
	    int r = *e;
	    if (l-1 >= 0 && r+1 < N && in(T[0], S[l-1]) && in(T.back(), S[r+1])) ans++;
	}
    }

    printf("%lld\n", ans);



    return 0;
}