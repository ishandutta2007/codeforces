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
vector<int>Z_Algorithm(const string&s) {
    int n=s.size();
    vector<int>z(n);
    int l = 0, r = 0;
    for (int i=1; i<n; i++) {
	if (i > r) {
	    l = r = i;
	    while (r<n && s[r-l] == s[r]) r++;
	    z[i] = r-l; r--;
	} else {
	    int k = i-l;
	    if (z[k] < r-i+1) z[i] = z[k];
	    else {
		l = i;
		while (r<n && s[r-l] == s[r]) r++;
		z[i] = r-l; r--;
	    }
	}
    }
    return z;
}

int N, K;
char S[1000111];
LL P[1000111];
int main() {
    scanf("%d%d%s", &N, &K, S);
    string st = S;
    VI Z = Z_Algorithm(S);
    for (LL L=1; L<=N; L++) {
	if (L * K > N) break;
//	eprintf("%llu\n", R.get(0, L));
	bool ok = true;
	for (int i=1; i<K; i++) {
	    if (Z[L*i] < L) {
		ok = false;
		break;
	    }
	}
	if (!ok) continue;

	int lo = 0, hi = L+1;
	while (hi-lo > 1) {
	    int m = (lo+hi)/2;
	    if (L*K+m > N || Z[L*K] < m) hi = m;
	    else lo = m;
	}
//	eprintf("%d %d\n", L, lo);
	P[L*K-1]++;
	P[L*K+lo]--;
    }
    
    REP (i, N) {
	P[i+1] += P[i];
	printf("%d", P[i]? 1: 0);
    }
    putchar('\n');
    
    return 0;
}