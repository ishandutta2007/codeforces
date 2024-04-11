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

const LL MOD = 1e9 + 7;
LL powMod(LL x, LL y) {
    LL r = 1;
    for (; y ; y>>=1) {
	if (y&1) r = r * x % MOD;
	x = x * x % MOD;
    }
    return r;
}

int N;
char S[100011];

int main() {
    scanf("%d%s", &N, S);
    map<char, int> cnt;
    for (int i=0; S[i]; i++) cnt[S[i]]++;

    int best = 0, tm = 0;
    EACH (e, cnt) {
	if (best < e->second) {
	    best = e->second;
	    tm = 0;
	}
	if (best == e->second) {
	    tm++;
	}
    }
    printf("%d\n", (int)powMod(tm, N));

    return 0;
}