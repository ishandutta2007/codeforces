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

int N, M;
char A[100011];
VI G[100011];
int ans;
void dfs(int v, int p, int c) {
    if (A[v] == '1') {
	if (c+1 > M) return;
	c++;
    } else {
	c = 0;
    }
    int k = 0;
    EACH (e, G[v]) if (*e != p) {
	k++;
	dfs(*e, v, c);
    }
    if (k == 0) ans++;
}

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", A+i);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }
    dfs(0, 0, 0);
    printf("%d\n", ans);
    return 0;
}