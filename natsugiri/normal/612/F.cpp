#include<cassert>
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

template<class T> vector<int> compress(const vector<T> &v, vector<T> *unq=NULL) {
    int n = v.size();
    vector<pair<T, int> > t(n);
    for (int i=0; i<n; i++) t[i] = make_pair(v[i], i);
    sort(t.begin(), t.end());
    vector<int> r(n);
    int cur = 0;
    for (int i=0, k=0; i<n; i++) {
	if (t[k].first < t[i].first) k = i, cur++;
	r[t[i].second] = cur;
    }
    if (unq) {
	unq->resize(cur+1);
	cur = 0;
	for (int i=0; i<n; i++)
	    if (i == 0 || t[i-1].first < t[i].first)
		(*unq)[cur++] = t[i].first;
    }
    return r;
}

int N, S;
int A[2011];
VI G[2011];

int INF;
int dp[2011][2011];
int from[2011][2011], start[2011][2011];

int cost(int a, int b) {
    return min(abs(a-b), N-abs(a-b));
}
int main() {
    scanf("%d%d", &N, &S);
    S--;
    REP (i, N) scanf("%d", A+i);

    VI C = compress(VI(A, A+N));
    
    REP (i, N) {
	G[C[i]].push_back(i);
    }
    
    memset(dp, 0x3f, sizeof dp);
    memset(&INF, 0x3f, sizeof INF);
    
    dp[0][S] = 0;
    int cur = 0;
    REP (i, N) if (G[i].size()) {
	sort(G[i].begin(), G[i].end());

	REP (k, N) if (dp[cur][k] != INF) {
	    int sz = G[i].size();
	    REP (j, G[i].size()) {
		int K[2] = { G[i][(j+sz-1)%sz], G[i][(j+1)%sz] };
		REP (z, 2) {
		    int cst = cost(k, G[i][j]);
		    if (G[i].size() == 1u) ;
		    else if (G[i].size() == 2u) cst += cost(G[i][j], K[z]);
		    else if (z == 0) cst += N - (G[i][j] - K[z] + N) % N;
		    else cst += N - (K[z] - G[i][j] + N) % N;
		    
		    if (dp[cur+1][K[z]] > cst + dp[cur][k]) {
			dp[cur+1][K[z]] = cst + dp[cur][k];
			from[cur+1][K[z]] = k;
			start[cur+1][K[z]] = G[i][j];
		    }
		}
	    }
	}
	cur++;
	// REP (j, N) eprintf("%d ", dp[cur][j]); eprintf("\n");
    }

    int T = 0;

    REP (i, N) if (dp[cur][T] > dp[cur][i]) {
	T = i;
    }
    
    printf("%d\n", dp[cur][T]);
    VI ans;
    for (int i=N; i--;) {
	if (G[i].size() == 0u) continue;

	int sz = G[i].size();
	REP (j, G[i].size()) {
	    if (G[i][j] == T) {
		int d = 0;
		if (G[i][(j+1)%sz] == start[cur][T]) {
		    d = -1;
		} else {
		    d = +1;
		}
		int jj=j;
		REP (p, sz) {
		    ans.push_back(G[i][jj]);
		    jj = (jj+d+sz)%sz;
		}

		T = from[cur][T];
		break;
	    }
	}

	cur--;
    }

    assert(T == S);
    ans.push_back(S);
    reverse(ans.begin(), ans.end());
    REP (i, N) {
	int a[] = { (ans[i+1] - ans[i] + N) % N,
		    (ans[i] - ans[i+1] + N) % N };
	if (a[0] <= a[1]) printf("+%d\n", a[0]);
	else printf("-%d\n", a[1]);
    }
    return 0;
}