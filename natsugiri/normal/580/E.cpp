#include<cassert>
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

typedef unsigned long long ULL;
typedef unsigned int Uint;
struct SegmentTree {
    int n, m;
    ULL M;
    vector<Uint> d, p, ex, exx;
    vector<char> f;
    SegmentTree(){}
    SegmentTree(char *s, int n, ULL A, ULL M_): n(n), M(M_) {
	for (m=1;m<n;) m*=2;
	d = vector<Uint>(m*2);
	p = vector<Uint>(m*2, 1);
	f = vector<char>(m*2, -1);
	ex = vector<Uint>(m*2);
	exx = vector<Uint>(m*2+1);
	ex[0] = 1;
	REP (i, 2*m-1) ex[i+1] = (ULL)ex[i] * A % M;
	REP (i, 2*m) exx[i+1] = ((ULL)exx[i] + ex[i]) % M;
	
	REP (i, n) {
	    int k = s[i] - '0';
	    d[i+m] = k;
	}
	
	for (int i=m; --i; ) {
	    d[i] = ((ULL)d[i*2] * ex[p[i*2]] + d[i*2+1]) % M;
	    p[i] = p[i*2] + p[i*2+1];
	}
    }
    void down(int k, int l, int r) {
	if (f[k] != -1) {
	    d[k] = (ULL)exx[r-l] * f[k] % M;
	    if (k*2+1 < 2*m) f[k*2] = f[k*2+1] = f[k];
	    f[k] = -1;
	}
    }
    void up(int k, int l, int r) {
	if (2*k+1 < 2*m) {
	    down(k*2, l, (l+r)/2); down(k*2+1, (l+r)/2, r);
	    d[k] = ((ULL)d[k*2] * ex[(r-l)/2] + d[k*2+1]) % M;
	}
    }
    ULL query(int x, int y) { return query(x, y, 1, 0, m); }
    ULL query(int x, int y, int k, int l, int r) {
	if (r<=x || y<=l) return 0;
	down(k, l, r);
	if (x<=l && r<=y) {
	    return d[k];
	}
	ULL le = query(x, y, k*2, l, (l+r)/2);
	ULL ri = query(x, y, k*2+1, (l+r)/2, r);
	int len = max(0, min(y, r) - (l+r)/2);
	up(k, l, r);
	return (le * ex[len] + ri) % M;
    }
    void set(int x, int y, int v) { set(x, y, v, 1, 0, m);  }
    void set(int x, int y, int v, int k, int l, int r) {
	if (r<=x || y<=l) return;
	if (x<=l && r<=y) {
	    f[k] = v;
	    down(k, l, r);
	    return ;
	}
	down(k, l, r);
	set(x, y, v, k*2, l, (l+r)/2);
	set(x, y, v, k*2+1, (l+r)/2, r);
	up(k, l, r);
	// d[k] = ((ULL)d[k*2] * ex[p[k*2]] + d[k*2+1]) % M;
    }
};

int N, M, K;
char S[100011];
int main() {
    scanf("%d%d%d", &N, &M, &K);
    scanf("%s", S);
    
    SegmentTree X(S, N, 1e9+7, 1e9+9);
    SegmentTree Y(S, N, 1e9+21, 1e9+33);

    REP (_, M+K) {
	char op[9]; int l, r, c;
	scanf("%s%d%d%d", op, &l, &r, &c);
	l--;
	
	if (op[0] == '1') {
	    X.set(l, r, c);
	    Y.set(l, r, c);
	} else {
	    bool yes =
		X.query(l, r-c) == X.query(l+c, r) &&
		Y.query(l, r-c) == Y.query(l+c, r);
	    puts(yes? "YES": "NO");
	}
    }
    
    return 0;
}