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

const LL MOD = 1000000007;
const int MAX = 1000000;
LL inv[MAX+1], fact[MAX+1], fact_inv[MAX+1];

void init() {
    inv[1] = 1;
    for (int i=2; i<=MAX; i++) inv[i] = inv[MOD%i] * (MOD-MOD/i) % MOD;

    fact[0] = fact_inv[0] = 1;
    for (int i=1; i<=MAX; i++) {
	fact[i] = fact[i-1] * i % MOD;
	fact_inv[i] = fact_inv[i-1] * inv[i] % MOD;
    }
}

LL nCk(int n, int k) {
    return fact[n] * fact_inv[k] % MOD * fact_inv[n-k] % MOD;
}


int H, W, N;
int main() {
    init();
    scanf("%d%d%d", &H, &W, &N);
    vector<pair<int, int> > C;
    C.push_back(make_pair(1, 1));
    C.push_back(make_pair(H, W));
    REP (i, N) {
	int a, b;
	scanf("%d%d", &a, &b);
	C.push_back(make_pair(a, b));
    }
    sort(C.begin(), C.end());

    if (H == 1 && W == 1) {
	puts("1");
	return 0;
    }
    
    vector<LL> dp(C.size());
    dp[0] = MOD-1;
    REP (i, C.size()) {
	for (int j=i+1; j<(int)C.size(); j++) {
	    int y = C[j].first - C[i].first;
	    int x = C[j].second - C[i].second;
	    if (y >= 0 && x >= 0) {
		dp[j] -= dp[i] * nCk(x+y, x) % MOD;
		if (dp[j] < 0) dp[j] += MOD;
	    }
	}
    }

    LL ans = dp.back();
    ans = (ans % MOD + MOD) % MOD;
    printf("%lld\n", ans);
    return 0;
}