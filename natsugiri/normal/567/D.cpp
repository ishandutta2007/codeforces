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

int N, K, A, C[200011], M;
bool use[200011];
int sum;
set<pair<int, int> > se;

void add(int x, int y) {
    if (y-x < A) return;
    sum += (y-x+1) / (A+1);
    se.insert(make_pair(x, y));
}

int main() {
    scanf("%d%d%d", &N, &K, &A);

    add(1, N+1);
    if (sum < K) {
	puts("0");
	return 0;
    }
    
    scanf("%d", &M);
    REP (i, M) {
	int X; scanf("%d", &X);

	if (use[X]) continue;
	set<pair<int, int> >::iterator it = se.upper_bound(make_pair(X, N+2));
	if (it == se.begin()) continue;
	pair<int,int> p = *(--it);
	if (X < p.first || p.second <= X) continue;
	se.erase(it);
	
	sum -= (p.second - p.first + 1) / (A + 1);
	use[X] = true;
	add(p.first, X);
	add(X+1, p.second);

	if (sum < K) {
	    printf("%d\n", i+1);
	    return 0;
	}
    }

    puts("-1");
    
    return 0;
}