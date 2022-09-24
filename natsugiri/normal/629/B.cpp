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

int N, M[444], F[444];
int main() {
    scanf("%d", &N);
    REP (i, N) {
	char cc[9];
	int a, b;
	scanf("%s%d%d", cc, &a, &b);
	if (cc[0] == 'M') { M[a]++; M[b+1]--; }
	else { F[a]++; F[b+1]--; }
    }
    REP (i, 400) {
	F[i+1] += F[i];
	M[i+1] += M[i];
    }

    int ans = 0;
    for (int i=1; i<=366; i++) amax(ans, 2*min(F[i], M[i]));
    printf("%d\n", ans);
	    
    return 0;
}