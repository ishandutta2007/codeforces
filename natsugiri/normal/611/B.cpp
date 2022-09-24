#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

vector<ULL> G;


ULL A, B;
int main() {
    for (int i=1; i<62; i++) {
	for (int j=0; j<i-1; j++) {
	    G.push_back(((1ull<<i)-1) & ~(1ull<<j));
	}
    }
    sort(G.begin(), G.end());

    scanf("%llu%llu", &A, &B);
    // REP (i, G.size()) if (A <= G[i] && G[i] <= B) cerr << G[i] <<endl;
    printf("%lu\n", upper_bound(G.begin(), G.end(), B) - lower_bound(G.begin(), G.end(), A));
    return 0;
}