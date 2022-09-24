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

int N;
LL V[4011], D[4011], P[4011];
int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld%lld%lld", V+i, D+i, P+i);

    VI ans;
    
    REP (i, N) if (P[i] >= 0) {
	ans.push_back(i);
	for (LL j=i+1, z=V[i], k=0; j<N; j++) {
	    if (P[j] >= 0) {
		P[j] -= max(0LL, z)+k;
		z--;
		if (P[j] < 0) k += D[j];
	    }
	}
	// REP (j, N) eprintf("(%d, %d) ", j+1, P[j]); eprintf("\n");
    }

    printf("%lu\n", ans.size());
    REP (i, ans.size()) printf("%d%c", ans[i]+1, i+1==(int)ans.size()? '\n' :' ');
    
    return 0;
}