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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int N, M;
int B[200111], C[200111];
map<int, int> mp;

int main() {

    scanf("%d", &N);
    REP (i, N) {
	int x;
	scanf("%d", &x);
	mp[x]++;
    }
    scanf("%d", &M);
    REP (i, M) scanf("%d", B+i);
    REP (i, M) scanf("%d", C+i);

    int p = 0;
    int pb = 0, pc = 0;
    REP (i, M) {
	int ib = (mp.find(B[i]) == mp.end()? 0: mp[B[i]]);
	int ic = (mp.find(C[i]) == mp.end()? 0: mp[C[i]]);
	if (pb < ib || (pb == ib && pc < ic)) {
	    p = i;
	    pb = ib;
	    pc = ic;
	}
    }

    printf("%d\n", p + 1);

    return 0;
}