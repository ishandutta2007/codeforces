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
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

const int INF = 1<<29;

int N, M;
VI G[3011];

int S[2], T[2], L[2];

VI D[3011];


int main() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int a, b;
	scanf("%d%d", &a, &b);
	a--; b--;
	G[a].push_back(b);
	G[b].push_back(a);
    }

    REP (i, 2) {
	scanf("%d%d%d", S+i, T+i, L+i);
	S[i]--; T[i]--;
    }

    REP (i, N) {
	D[i].assign(N, INF);
	queue<int> qu;
	qu.push(i);
	D[i][i] = 0;
	while (!qu.empty()) {
	    int v = qu.front(); qu.pop();
	    EACH (e, G[v]) if (D[i][*e] == INF) {
		D[i][*e] = D[i][v] + 1;
		qu.push(*e);
	    }
	}
    }

    int ans = -1;
    REP (i, N) REP (j, N) {
	int g = 0;
	bool ok = true;
	REP (k, 2) {
	    int len = 
		min(D[S[k]][i] + D[i][j] + D[j][T[k]],
		    D[T[k]][i] + D[i][j] + D[j][S[k]]);
	    if (len > L[k]) ok = false;
	    g += len;
	}
	if (!ok) continue;
	
	g -= D[i][j];
//	eprintf("%d %d %d\n", i+1, j+1, g);
	amax(ans, M - g);
    }


    {
	int g = 0;
	bool ok = true;
	REP (k, 2) {
	    int len = D[S[k]][T[k]];
	    if (len > L[k]) ok = false;
	    g += len;
	}
	if (ok) {
	    amax(ans, M - g);
	}
    }
    printf("%d\n", ans);
    
    return 0;
}