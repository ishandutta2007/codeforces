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
int nd, md;
int dig(int x) {
    x--;

    if (x == 0) return 1;

    int r = 0;
    while (x) {
	x /= 7;
	r++;
    }
    return r;
}

int ans;
bool use[11];
void rec(int I, int A) {
    if (I < nd) {
	REP (k, 7) {
	    if (A * 7 + k >= N) break;
	    if (!use[k]) {
		use[k] = true;
		rec(I+1, (I == nd-1 ? 0: A * 7 + k));
		use[k] = false;
	    }
	}
    } else if (I < nd + md) {
	REP (k, 7) {
	    if (A * 7 + k >= M) break;
	    if (!use[k]) {
		use[k] = true;
		rec(I+1, A * 7 + k);
		use[k] = false;
	    }
	}
    } else {
	ans++;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    nd = dig(N);
    md = dig(M);

    rec(0, 0);
    printf("%d\n", ans);
    return 0;
}