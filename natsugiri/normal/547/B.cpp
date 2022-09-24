#include<set>
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
pair<int, int> A[200011];
pair<int, int> X[200011];

int main() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%d", &A[i].first);
	A[i].second = i;
    }

    sort(A, A+N);
    A[N] = make_pair(A[N-1].first+1, N);
    
    set<int> se;
    multiset<int> len;
    se.insert(-1);
    se.insert(N);
    len.insert(N);

    int cnt = 0;
    X[cnt++] = make_pair(0, N);
    
    for (int i=0; i<N; ) {
	int last = A[i].first;

	for (; last == A[i].first; i++) {
	    set<int>::iterator it = se.insert(A[i].second).first;
	    int hi = *(++it); it--;
	    int lo = *(--it); it++;

	    len.erase(len.find(hi - lo - 1));
	    if (hi - A[i].second - 1 > 0) len.insert(hi - A[i].second -1);
	    if (A[i].second - lo - 1 > 0) len.insert(A[i].second - lo - 1);
	}
	if (len.size()) X[cnt++] = make_pair(last, *len.rbegin());
	else X[cnt++] = make_pair(last, 0);
    }

    for (int i=1, j=cnt-1; i<=N; i++) {
	while (j && X[j-1].second < i) j--;
    	printf("%d%c", X[j].first, i==N?'\n':' ');
    }

    
//    REP (i, cnt) eprintf("%d %d\n", X[i].first, X[i].second);
    
    return 0;
}