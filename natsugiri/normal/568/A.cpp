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

const int MAX = 2000000;
int pi[MAX], rub[MAX];

bool pal(int n) {
    int r = 0;
    for (int m=n; m; m/=10) {
	r = r * 10 + m % 10;
    }
    return r == n;
}

int P, Q;
int main() {
    REP (i, MAX) pi[i] = 1;
    pi[0] = pi[1] = 0;
    for (int i=2; i*i<=MAX; i++) {
	for (int j=i*i; j<MAX; j+=i) pi[j] = 0;
    }
    for (int i=1; i<MAX; i++) pi[i] += pi[i-1];

    for (int i=1; i<MAX; i++) rub[i] = rub[i-1] + pal(i);

//    printf("%d %d\n", pi[MAX-1], 42 * rub[MAX-1]);
    scanf("%d%d", &P, &Q);

    int ans = 0;
    REP (i, MAX) {
	if ((LL)Q*pi[i] <= (LL)P*rub[i]) ans = i;
    }

    printf("%d\n", ans);
    
    return 0;
}