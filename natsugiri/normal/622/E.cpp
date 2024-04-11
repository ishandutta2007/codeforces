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

int N;
VI G[500011];
int dep[500011];

int calc(int s) {
    dep[s] = 1;
    VI ord;
    ord.push_back(s);
    VI l;
    for (int i=0; i<(int)ord.size(); i++) {
	int v = ord[i];
	EACH (e, G[v]) if (dep[*e] == -1) {
	    dep[*e] = dep[v] + 1;
	    ord.push_back(*e);
	}
	if (v != 0 && G[v].size() == 1u) l.push_back(dep[v]);
    }
    
    sort(l.begin(), l.end());
    int last = -1;
    EACH (e, l) {
	last = max(last + 1, *e);
    }
    return last;
}

int main() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    int ans = 0;
    memset(dep, -1, sizeof dep);
    dep[0] = 0;
    EACH (e, G[0]) amax(ans, calc(*e));
    printf("%d\n", ans);
    
    return 0;
}