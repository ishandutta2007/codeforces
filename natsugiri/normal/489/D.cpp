#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

template<class T> inline T &amin(T &a, T b) { if (a>b) a=b; return a; }
template<class T> inline T &amax(T &a, T b) { if (a<b) a=b; return a; }

vector<int> G[3011];
int N, M;
LL ans;

int C[3011];

int main() {
    scanf("%d%d", &N, &M);

    REP (i, M) {
	int S, T;
	scanf("%d%d", &S, &T);
	S--; T--;
	
	G[S].push_back(T);
    }

    REP (a, N) {
	memset(C, 0, sizeof C);

	REP (i, G[a].size()) {
	    int b = G[a][i];
	    REP (i, G[b].size()) { // c := G[b][i]
		C[G[b][i]]++;
	    }
	}

	REP (c, N) {
	    if (c==a) continue;
	    ans += (LL)C[c] * (C[c]-1) / 2;
	}
    }

    //printf("%d\n", ans/2);
    printf("%lld\n", ans);
    return 0;
}