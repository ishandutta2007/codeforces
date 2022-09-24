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

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

const LL MOD = 1e9+7;

int N;
VI G[200011];

vector<LL> prodL[200011], prodR[200011];
LL par[200011];

int main() {
    scanf("%d", &N);

    REP (i, N-1) {
	int p; scanf("%d", &p);
	p--;
	G[p].push_back(i+1);
    }

    for (int i=N; i--;) {
	prodL[i].push_back(1);
	EACH (e, G[i]) {
	    prodL[i].push_back(prodL[*e].back()+1);
	    prodR[i].push_back(prodL[*e].back()+1);
	}
	prodR[i].push_back(1);

	int m = prodL[i].size();
	REP (k, m-1) {
	    prodL[i][k+1] = prodL[i][k+1] * prodL[i][k] % MOD;
	    prodR[i][m-2-k] = prodR[i][m-2-k] * prodR[i][m-1-k] % MOD;
	}

    }

    par[0] = 1;
    REP (i, N) {
	REP (k, G[i].size()) {
	    int c = G[i][k];
	    par[c] = par[i] * prodL[i][k] % MOD * prodR[i][k+1] % MOD + 1;
	}
	int out = par[i] * prodL[i].back() % MOD;

	printf("%d%c", out, i+1==N? '\n': ' ');
    }

    return 0;
}