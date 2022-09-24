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


int N, P[1000111];
int Q[1000111];

vector<VI> G[1000111];
bool use[1000111];

int main() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%d", P+i);
	P[i]--;
    }

    REP (i, N) if (!use[i]) {
	int cur = i;
	VI v;
	while (!use[cur]) {
	    use[cur] = true;
	    v.push_back(cur);
	    cur = P[cur];
	}
	G[v.size()].push_back(v);
    }


    REP (i, N+1) {
	if (G[i].size() == 0u) continue;
	if (i&1) {
	    EACH (e, G[i]) {
		int p = i/2;
		REP (k, i) {
		    Q[(*e)[p]] = (*e)[k];
		    p++;
		    if (p == i) p = 0;
		}
	    }
	} else {
	    if (G[i].size() & 1) {
		puts("-1");
		return 0;
	    }

	    for (int k=0; k<(int)G[i].size(); k+=2) {
		const VI a = G[i][k];
		const VI b = G[i][k+1];
		REP (t, i) {
		    Q[a[t]] = b[t];
		    Q[b[t]] = a[(t+1)%i];
		}
	    }
	}
    }

    REP (i, N) printf("%d%c", Q[i]+1, i==N-1?'\n':' ');
    
    return 0;
}