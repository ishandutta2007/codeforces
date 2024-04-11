#include<cmath>
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

template<class T> inline void amin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, T b) { if (a<b) a=b; }

int N, L[5], R[5];
int A[5];
double rec(int cnt) {
    double ret = 0;
    if (cnt == N) {
	int t = 0, l = 0;
	REP (i, N) {
	    if (A[i] == 2) t++;
	    if (A[i] == 1) l++;
	}
	if (t > 1 || l == 0 || t+l<2) return 0;

	REP (v, 10011) {
	    bool ok = true;
	    double tmp = 1;
	    REP (i, N) {
		if (A[i] == 0) {
		    // L ~ min(R, v-1)
		    if (v-1 < L[i]) ok = false;
		    tmp *= (min(v-1, R[i])-L[i]+1.0)/(R[i]-L[i]+1.0);
		} else if (A[i] == 1) {
		    if (v < L[i] || R[i] < v) ok = false;
		    tmp *= 1.0/(R[i]-L[i]+1.0);
		} else {
		    // max(L, v+1) ~ R
		    if (R[i] < v+1) ok = false;
		    tmp *= (R[i]-max(L[i], v+1)+1.0)/(R[i]-L[i]+1.0);
		}
	    }
	    if (ok) ret += tmp * v;

	}
	return ret;
    }
    REP (i, 3) {
	A[cnt] = i;
	ret += rec(cnt+1);
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", L+i, R+i);

    double ans = rec(0);

    printf("%.12f\n", ans);

    return 0;
}