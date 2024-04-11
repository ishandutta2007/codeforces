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

const int S[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
int A, B;
int main() {
    scanf("%d%d", &A, &B);
    int ans = 0;
    for (int i=A; i<=B; i++) {
	int m = i;
	while (m) {
	    ans += S[m % 10];
	    m /= 10;
	}
    }
    printf("%d\n", ans);
    return 0;
}