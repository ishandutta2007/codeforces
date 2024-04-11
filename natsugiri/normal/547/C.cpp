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

const int MAX = 500011;

int N, Q, A[200011];
int freq[MAX];
VI D[MAX];

bool on[200011];
int CNT[MAX];
bool prime[MAX];
int moebius[MAX];


int main() {
    scanf("%d%d", &N, &Q);
    REP (i, N) {
	scanf("%d", A+i);
	freq[A[i]]++;
    }

    for (int i=1; i<MAX; i++) {
	for (int j=i; j<MAX; j+=i) {
	    if (freq[j]) D[j].push_back(i);
	}
    }

    REP (i, MAX) {
	prime[i] = true;
	moebius[i] = 1;
    }
    for (int i=2; i<MAX; i++) {
	if (prime[i]) {
	    moebius[i] = -1;
	    for (int j=i+i; j<MAX; j+=i) {
		prime[j] = false;
		moebius[j] *= ((j % (i*i) == 0) ? 0 : -1);
	    }
	}
    }

    LL sum = 0;
    REP (q, Q) {
	int x; scanf("%d", &x); x--;
	int G = A[x];

	LL ad = 0;
	
	if (on[x]) {
	    EACH (e, D[G]) CNT[*e]--;
	    EACH (e, D[G]) {
		ad += moebius[*e] * CNT[*e];
	    }
	    sum -= ad;
	} else {
	    EACH (e, D[G]) {
		ad += moebius[*e] * CNT[*e];
	    }
	    sum += ad;
	    EACH (e, D[G]) CNT[*e]++;
	}

	on[x] = !on[x];
	printf("%lld\n", sum);
    }
    
    return 0;
}