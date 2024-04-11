#include<map>
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

const LL MOD = 1e9+7;

int M;
map<int, int> X;
LL L[200111], R[200111];

LL powMod(LL x, LL y, LL m) {
    LL r= 1;
    for (;y;y>>=1) {
	if (y&1) r = r * x % m;
	x = x* x % m;
    }
    return r;
}
int main() {
    scanf("%d", &M);
    REP (i, M) {
	int p;
	scanf("%d", &p);
	X[p] += 1;
    }

    vector<pair<int, int> > G(X.begin(), X.end());

    L[0] = 1;
    REP (i, G.size()) {
	L[i+1] = L[i] * (G[i].second + 1) % (MOD - 1);
    }
    R[G.size()] = 1;
    for (int i=G.size(); i--;) {
	R[i] = R[i+1] * (G[i].second + 1) % (MOD - 1);
    }

    LL ans = 1;
    REP (i, G.size()) {
	LL p = L[i] * R[i+1] % (MOD - 1);
	LL z = (LL)G[i].second * (G[i].second + 1) / 2 % (MOD - 1);
	p = p * z % (MOD - 1);
	ans = ans * powMod(G[i].first, p, MOD) % MOD;
    }

    printf("%lld\n", ans);
    return 0;
}