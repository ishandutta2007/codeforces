#include<queue>
#include<map>
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

const int INF = 1e9;
const int MAX = 100000;
int N, A[100011], B[100011], C[100011], Z[100011];;
int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    // N = 100000;
    // REP (i, N) A[i] = (1<<16)-1;
    // sort(A, A+N);

    REP (i, N) {
	queue<pair<int,int> > qu;
	qu.push(make_pair(A[i], 0));

	while (qu.size()) {
	    pair<int,int> p = qu.front(); qu.pop();

	    
	    if (p.first > MAX || Z[p.first] == i+1) continue;
	    Z[p.first] = i+1;
	    
	    if (B[p.first] == i) {
		B[p.first] = i+1;
		C[p.first] += p.second;
	    }
	    qu.push(make_pair(p.first*2, p.second+1));
	    qu.push(make_pair(p.first/2, p.second+1));
	}
    }

    int ans = INF;
    REP (i, MAX+1) if (B[i] == N) amin(ans, C[i]);


    printf("%d\n", ans);
    return 0;
}