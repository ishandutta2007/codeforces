#include<set>
#include<queue>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int N, M;
int P[200111];
int S[200111];
int ad[200111];
int co[200111];

struct Socket {
    int d;
    int id;
    int po;
    bool operator<(const Socket &y) const {
	return y.d < d;
    }
    Socket next() const {
	Socket s = *this;
	s.d++;
	s.po = (s.po + 1) / 2;
	return s;
    }
};

int main() {

    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", P+i);
    REP (i, M) scanf("%d", S+i);

    set<pair<int, int> > se; // (power, id)
    priority_queue<Socket> pq;

    REP (i, N) se.insert(make_pair(P[i], i));
    REP (i, M) pq.push((Socket){ 0, i, S[i] } );

    memset(co, -1, sizeof co);

    while (!se.empty() && !pq.empty()) {
	Socket s = pq.top(); pq.pop();

	set<pair<int, int> >::iterator it = se.lower_bound(make_pair(s.po, -1));
	if (it != se.end() && it->first == s.po) {
	    ad[s.id] = s.d;
	    co[it->second] = s.id;
	    se.erase(it);
	} else if (s.po > 1) {
	    pq.push(s.next());
	}
    }

    int C = 0, U = 0;
    REP (i, N) if (co[i] != -1) C++;
    REP (i, M) U += ad[i];

    printf("%d %d\n", C, U);
    REP (i, M) printf("%d%c", ad[i], i==M-1? '\n': ' ');
    REP (i, N) printf("%d%c", co[i] + 1, i==N-1? '\n': ' ');


    return 0;
}