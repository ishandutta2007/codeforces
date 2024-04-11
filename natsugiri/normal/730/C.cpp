#include<queue>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }


int N, M;
VI G[5001];
int W;
int C[5001], K[5001], P[5001];
int len[5001][5001], ord[5001][5001], stop[5001];
VI S[5001];

int main() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    scanf("%d", &W);
    REP (i, W) {
	scanf("%d%d%d", C+i, K+i, P+i);
	C[i]--;
	S[C[i]].push_back(i);
    }

    memset(len, 0x3f, sizeof len);
    REP (s, N) {
	len[s][s] = 0;
	ord[s][stop[s]++] = s;
	for (int i_=0; i_<stop[s]; i_++) {
	    int v = ord[s][i_];
	    EACH (e, G[v]) if (len[s][*e] > N) {
		len[s][*e] = len[s][v] + 1;
		ord[s][stop[s]++] = *e;
	    }
	}
    }

    int Q;
    scanf("%d", &Q);
    REP ($, Q) {
	int g, r, a;
	scanf("%d%d%d", &g, &r, &a);
	g--;

	int ans = -1;

	priority_queue<pair<int, int> > pq; // (cost, count);
	LL have = 0;
	LL cost = 0;

	REP (i, stop[g]) {
	    int v = ord[g][i];
	    EACH (e, S[v]) {
		// shop *e
		have += K[*e];
		cost += (LL)P[*e] * K[*e];
		pq.push(make_pair(P[*e], K[*e]));
		while (have > r) {
		    pair<int, int> p = pq.top(); pq.pop();
		    LL cnt = min(have - r, (LL)p.second);
		    have -= cnt;
		    cost -= cnt * p.first;
		    p.second -= cnt;
		    if (p.second) pq.push(p);
		}

		if (have == r && cost <= a) {
		    ans = len[g][v];
		    break;
		}
	    }
	    if (ans != -1) break;
	}

	printf("%d\n", ans);
    }
    


    return 0;
}