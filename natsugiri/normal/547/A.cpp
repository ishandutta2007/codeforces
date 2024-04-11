#include<set>
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

LL M;
LL H[2], A[2], X[2], Y[2];
int mem[2][1000011], memQ[1000011];
vector<LL> ord[2];
LL cycle[2], tail[2];

void one(int i) {
    scanf("%lld%lld%lld%lld", H+i, A+i, X+i, Y+i);
    memset(mem[i], -1, sizeof mem[i]);
    LL cur = H[i];
    LL cnt = 0;
    while (mem[i][cur] == -1) {
	ord[i].push_back(cur);
	mem[i][cur] = cnt++;
	cur = (X[i] * cur + Y[i]) % M;
    }
    tail[i] = mem[i][cur];
    cycle[i] = cnt - mem[i][cur];
}

int main() {
    scanf("%lld", &M);
    one(0); one(1);

    if (mem[0][A[0]] == -1 || mem[1][A[1]] == -1) {
	puts("-1");
	return 0;
    }

    REP (z, M+10) {
	LL T = mem[0][A[0]] + cycle[0] * z;

	int cnt = 0;
	REP (i, 2) {
	    LL pos = T;
	    if (T >= tail[i]) {
		pos = (T - tail[i]) % cycle[i] + tail[i];
	    }
	    if (ord[i][pos] == A[i]) cnt++;
	}
	if (cnt == 2) {
	    printf("%lld\n", T);
	    return 0;
	}
    }
    
    puts("-1");

    return 0;
}