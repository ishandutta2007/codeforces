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
LL X1, X2, K[100011], B[100011];

int main() {
    scanf("%d%lld%lld", &N, &X1, &X2);
    REP (i, N) scanf("%lld%lld", K+i, B+i);

    vector<pair<LL, LL> > v(N);
    REP (i, N) {
	v[i] = make_pair(K[i] * X1 + B[i], K[i] * X2 + B[i]);
    }

    sort(v.begin(), v.end());
    bool yes = false;
    REP (i, N-1) {
	if (v[i].first < v[i+1].first && v[i].second > v[i+1].second) {
	    yes = true;
	    break;
	}
    }
    puts(yes? "YES": "NO");
    return 0;
}