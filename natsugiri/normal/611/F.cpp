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
void add(LL &x, const LL &y) {
    if ((x+=y) >= MOD) x -= MOD;
}

const int MAXN = 500111;
int N, H, W;
char S[MAXN];
int sumY[MAXN], sumX[MAXN];

int main() {

    scanf("%d%d%d%s", &N, &H, &W, S);
    REP (i, N) {
	sumY[i+1] = sumY[i];
	sumX[i+1] = sumX[i];
	if (false) ;
	else if (S[i] == 'R') sumX[i+1]++;
	else if (S[i] == 'L') sumX[i+1]--;
	else if (S[i] == 'U') sumY[i+1]++;
	else if (S[i] == 'D') sumY[i+1]--;
    }

    LL ans = 0;
    // first time
    int L, R, D, U;
    L = R = D = U = 0;
    for (LL i=1; i<=N && W && H; i++) {
	if (R < sumX[i]) {
	    add(ans, i*H % MOD);
	    W--;
	    R = sumX[i];
	} else if (sumX[i] < L) {
	    add(ans, i*H % MOD);
	    W--;
	    L = sumX[i];
	} else if (U < sumY[i]) {
	    add(ans, i*W % MOD);
	    H--;
	    U = sumY[i];
	} else if (sumY[i] < D) {
	    add(ans, i*W % MOD);
	    H--;
	    D = sumY[i];
	}
    }

    // eprintf("ans %lld\n", ans);
    // eprintf("%d %d %d %d\n", L, R, D, U);
    
    // second
    vector<LL> v;
    int L_ = L, R_ = R, D_ = D, U_ = U;
    for (int i=1; i<=N; i++) {
	int y = sumY[N] + sumY[i];
	int x = sumX[N] + sumX[i];
	if (R < x) {
	    v.push_back(i);
	    R = x;
	} else if (x < L) {
	    v.push_back(i);
	    L = x;
	} else if (U < y) {
	    v.push_back(i);
	    U = y;
	} else if (y < D) {
	    v.push_back(i);
	    D = y;
	}
    }
    L = L_; R = R_; D = D_; U = U_;


    if (H && W && v.size() == 0u) { // loop
	puts("-1");
    } else {
	LL k = 1;
	while (H && W) {
	    EACH (e, v) {
		if (H == 0 || W == 0) break;
		int y = k * sumY[N] + sumY[*e];
		int x = k * sumX[N] + sumX[*e];
		LL rate = (k * N + *e) % MOD;
		
		if (R < x) {
		    add(ans, rate*H % MOD);
		    W--;
		    R = x;
		} else if (x < L) {
		    add(ans, rate*H % MOD);
		    W--;
		    L = x;
		} else if (U < y) {
		    add(ans, rate*W % MOD);
		    H--;
		    U = y;
		} else if (y < D) {
		    add(ans, rate*W % MOD);
		    H--;
		    D = y;
		}
	    }

	    k++;
	}

	printf("%d\n", (int)ans);
    }
    
	
    return 0;
}