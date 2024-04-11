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

int N, A[300011];
set<int> S;
vector<pair<int, int> >ans;
int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    int last = 0;
    REP (i, N) {
	if (!S.insert(A[i]).second) {
	    ans.push_back(make_pair(last, i));
	    last = i+1;
	    S.clear();
	}
    }

    if (ans.size() == 0u) {
	puts("-1");
    } else {
	ans.back().second = N-1;
	printf("%lu\n", ans.size());
	EACH (e, ans) printf("%d %d\n", e->first + 1, e->second+1);
	       
    }

    
    
    return 0;
}