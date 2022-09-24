#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

char S[5555];
int N, L;
LL calc(int p, int q) { // 0 .. [p, q) q .. L-1
    LL sum = 0, pro = S[2*p]-'0';
    
    for (int i=p+1; i<q; i++) {
	if (S[2*i-1] == '+') {
	    sum += pro;
	    pro = S[2*i]-'0';
	} else {
	    pro *= S[2*i]-'0';
	}
    }
    LL c = sum + pro, d = 0;
  
    if (p != 0) {
	sum = 0;
	pro = S[0]-'0';
	for (int i=1; i<p; i++) {
	    if (S[2*i-1] == '+') {
		sum += pro;
		pro = S[2*i]-'0';
	    } else {
		pro *= S[2*i]-'0';
	    }
	}
	c *= pro; d += sum;
    }

    if (q != L) {
	sum = 0;
	pro = S[2*L-2]-'0';
	for (int i=L-2; i>=q; i--) {
	    if (S[2*i+1] == '+') {
		sum += pro;
		pro = S[2*i]-'0';
	    } else {
		pro *= S[2*i]-'0';
	    }
	}
	c *= pro; d += sum;
    }
    
//    eprintf("[%d %d] %lld\n", p, q, c+d);
    return c + d;
}

VI K;

int main() {
    scanf("%s", S);
    N = strlen(S);
    L = (N+1)/2;

    K.push_back(0);
    REP (i, L-1) {
	if (S[2*i+1] == '*') K.push_back(i+1);
    }
    K.push_back(L);

    LL ans = 0;
    REP (j, K.size()) {
	REP (i, j) {
	    amax(ans, calc(K[i], K[j]));
	}
    }


    printf("%lld\n", ans);
    return 0;
}