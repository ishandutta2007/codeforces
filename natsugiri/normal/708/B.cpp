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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }


LL A, B, C, D;

int main() {
    scanf("%lld%lld%lld%lld", &A, &B, &C, &D);

    if (A + B + C + D == 0) {
	puts("0");
	return 0;
    }

    LL S = A + B + C + D;
    LL At = -1, Dt = -1, St = -1;

    for (LL x=0; x<=100000; x++) {
	LL t = x * (x - 1) / 2;
	if (t == A) At = x;
	if (t == D) Dt = x;
	if (t == S) St = x;
    }

    if (A == 0) {
	if (B + C) {
	    At = 1;
	} else {
	    At = 0;
	}
    }
    if (D == 0) {
	if (B + C) {
	    Dt = 1;
	} else {
	    Dt = 0;
	}
    }

    

    if (At == -1 || Dt == -1 || St == -1 || At + Dt != St) {
    } else {
	LL z = 0;
	while (Dt > 0 && (z+1) * At <= C && At * (Dt-1) >= B) {
	    z++;
	    Dt--;
	}


	if (z * At == C && At * Dt == B) {
	    puts((string(z, '1') + string(At, '0') + string(Dt, '1')).c_str());
	    return 0;
	} else {
	    if (Dt) {
		LL K[4] = {z, At, 0, Dt-1};
		while (K[1] && K[0] * At + K[2] < C && (Dt-1) * At + K[1] > B) {
		    K[1]--;
		    K[2]++;
		}

		if (K[0] * At + K[2] == C && (Dt-1) * At + K[1] == B) {
		    puts((string(K[0], '1')
				+ string(K[1], '0') 
				+ string(1, '1')
				+ string(K[2], '0')
				+ string(K[3], '1')).c_str());
		    return 0;
		} else {
		}
	    }
	}
    }

    puts("Impossible");
    return 0;
}