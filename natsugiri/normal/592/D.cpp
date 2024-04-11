#include<stack>
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
VI G[200011];
int A[200011];
int root;

int par[200011];

VI dist(int s) {
    VI len(N, -1);
    len[s] = 0;
    stack<int> X;
    X.push(s);
    while (!X.empty()) {
	int v = X.top(); X.pop();
	EACH (e, G[v]) if (len[*e] == -1 && A[*e]) {
	    len[*e] = len[v] + 1;
	    X.push(*e);
	}
    }
    return len;
}

int main() {
    scanf("%d%d", &N, &M);

    REP (i, N-1) {
	int a, b;
	scanf("%d%d", &a, &b);
	a--; b--;
	G[a].push_back(b);
	G[b].push_back(a);
    }
    REP (i, M) {
	int a;
	scanf("%d", &a);
	a--;
	root = a;
	A[a] = 1;
    }

    VI ord; ord.reserve(N);
    ord.push_back(root);
    par[root] = root;
    
    REP (i, N) {
	int v = ord[i];
	EACH (e, G[v]) if (*e != par[v]) {
	    par[*e] = v;
	    ord.push_back(*e);
	}
    }
    REP (i, N) {
	int v = ord[N-1-i];
	EACH (e, G[v]) if (*e != par[v]) {
	    if (A[*e]) {
		A[v] |= 2;
		break;
	    }
	}
    }

    int k = root;
    {
	VI len = dist(root);
	REP (i, N) {
	    if (len[i] > len[k]) k = i;
	    if (len[i] == len[k] && i < k) k = i;
	}
    }
    int k2 = k;
    VI len = dist(k);
    
    REP (i, N) {
	if (len[i] > len[k2]) k2 = i;
	if (len[i] == len[k2] && i < k2) k2 = i;
    }

    int cnt = 0;
    REP (i, N) if (A[i]) cnt++;

    printf("%d\n%d\n", min(k, k2) + 1, cnt * 2 - 2 - len[k2]);
    // eprintf("cnt : %d, len : %d\n", cnt, len[k2]);

    return 0;
}