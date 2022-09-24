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

int N, T;

int main() {
    scanf("%d%d", &N, &T);
    priority_queue<pair<int, int> > Q;
    REP (i, N) {
	int t, q;
	scanf("%d%d", &t, &q);
	Q.push(make_pair(-t, q));
    }

    while (Q.size() > 1u) {
	pair<int, int> A = Q.top(); Q.pop();
	pair<int, int> B = Q.top(); Q.pop();
	if (1-B.first > T) {
	    Q.push(A);
	    Q.push(B);
	    break;
	}
	
	if (A.first != B.first && !Q.empty()) {
	    pair<int, int> C = Q.top(); Q.pop();
	    if (B.first == C.first) {
		if (A.second > C.second) {
		    Q.push(C);
		    Q.push(make_pair(B.first-1, B.second + A.second));
		} else {
		    Q.push(A);
		    Q.push(make_pair(B.first-1, B.second + C.second));
		}
	    } else {
		Q.push(C);
		Q.push(make_pair(B.first-1, A.second + B.second));
	    }
	} else {
	    Q.push(make_pair(B.first-1, A.second + B.second));
	}
    }

    int ans = 0;
    while (!Q.empty()) {
	pair<int, int> A = Q.top(); Q.pop();
	if (-A.first <= T) amax(ans, A.second);
    }

    printf("%d\n", ans);
    
    return 0;
}