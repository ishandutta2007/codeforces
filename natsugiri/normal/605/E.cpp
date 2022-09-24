#include<queue>
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

int N;
double P[1011][1011];
double E[1011];
double a[1011], b[1011];
bool fix[1011];

double calc(int i) {
    return a[i] / (1 - b[i]);
}

int main() {
    scanf("%d", &N);
    REP (i, N) REP (j, N) {
	int x; scanf("%d", &x);
	P[i][j] = x / 100.0;
    }

    REP (i, N) {
	E[i] = 1e12;
	a[i] = 1.0;
	b[i] = 1.0;
    }
    E[N-1] = 0;
    fix[N-1] = true;
    priority_queue<pair<double, int> > Q;
    Q.push(make_pair(0, N-1));

    while (!Q.empty()) {
	int v = Q.top().second; Q.pop();
	int w = -1;
	REP (i, N) {
	    a[i] += b[i] * P[i][v] * E[v];
	    b[i] *= 1 - P[i][v];
	    if (!fix[i] && b[i] < 1.0 && (w == -1 || calc(w) > calc(i))) w = i;
	}
	if (w != -1 && b[w] < 1.0) {
	    E[w] = calc(w);
	    Q.push(make_pair(-E[w], w));
	    fix[w] = true;
	}
    }

    printf("%.12f\n", E[0]);

    return 0;
}