#include<queue>
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
template<class T>
struct Fenwick : vector<T> {
    typedef vector<T> S;
    int N;
    Fenwick(int N_=0): S(N_), N(N_) {}
    void add(int i, T x) {
	for (; i<N; i|=i+1) S::operator[](i) += x;
    }
    inline T sum(int r) {
	T s = 0;
	for (; r; r&=r-1) s += S::operator[](r-1);
	return s;
    }
    T sum(int l, int r) {
	return sum(r) - sum(l);
    }
    int lower_bound(T x) { // argmin_i x <= sum(0,i)
	int i = 1, j = 0;
	T s = T();
	while (i<N) i<<=1;
	for (; i; i>>=1) {
	    if (i+j <= N && s + S::operator[](i+j-1) < x) {
		s += S::operator[](i+j-1);
		j += i;
	    }
	}
	return j;
    }
};



const int MAXN = 3011;
int N, M;
char F[MAXN][MAXN];
int L[MAXN][MAXN], R[MAXN][MAXN];


LL calc(int y, int x) {
    LL ans = 0;
    Fenwick<LL> S(MAXN);
    priority_queue<pair<int, int> > Q; // (del_y, pos_y)
    
    REP (_, 3011) {
	while (!Q.empty() && Q.top().first == y) {
	    S.add(Q.top().second, -1);
	    Q.pop();
	}
	
	if (F[y][x] == 'z') {

	    int del = y - R[y][x];
	    S.add(y, 1);
	    Q.push(make_pair(del, y));

	    ans += S.sum(y, min(y+L[y][x], MAXN));

	} else {
	    while (!Q.empty()) {
		S.add(Q.top().second, -1);
		Q.pop();
	    }
	}
	
	y -= 1;
	x += 1;
	if (y < 0 || M <= x) break;
    }

    return ans;
}

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", F[i]);

    // N = M = 3000;
    // memset(F, 'z', sizeof F);

    REP (i, N) REP (j, M) {
	if (F[i][j] == 'z') {
	    L[i][j] = 1;
	    if (j) L[i][j] += L[i][j-1];
	}
    }
    REP (i, N) {
	for (int j=M-1; j>=0; j--) {
	    if (F[i][j] == 'z') {
		R[i][j] = R[i][j+1] + 1;
	    }
	}
    }

    
    LL ans = 0;
    REP (i, N-1) ans += calc(i, 0);
    REP (j, M) ans += calc(N-1, j);

    printf("%lld\n", ans);
    return 0;
}