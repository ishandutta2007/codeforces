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

int N, A[26];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    int odd = 0;
    int g = A[0];

    REP (i, N) {
	if (A[i] & 1) odd++;
	if (A[i] > 0) g = __gcd(g, A[i]);
    }

    if (N == 1) {
	printf("%d\n", A[0]);
	REP (i, A[0]) putchar('a');
	putchar('\n');
	
    } else if (odd > 1) {

	puts("0");
	REP (i, N) REP (j, A[i]) putchar('a'+i);
	putchar('\n');

    } else {
	printf("%d\n", g);
	string ans;
	REP (i, N) REP (j, A[i]/g/2) ans.push_back('a'+i);
	REP (i, N) if ((A[i]/g)&1) ans.push_back('a'+i);
	for (int i=N; i--; ) REP (j, A[i]/g/2) ans.push_back('a'+i);
	REP (i, g) {
	    printf("%s", ans.c_str());
	    reverse(ans.begin(), ans.end());
	}
	putchar('\n');

    }
    // } else if (odd == 1) {
	
    // 	puts("1");
    // 	string ans;
    // 	REP (i, N) REP (j, A[i]/2) ans.push_back('a'+i);
    // 	printf("%s", ans.c_str());
    // 	REP (i, N) if (A[i] & 1) putchar('a'+i);
    // 	reverse(ans.begin(), ans.end());
    // 	puts(ans.c_str());

    // } else {
    // 	printf("%d\n", g);

    // 	string ans;
    // 	REP (i, N) REP (j, A[i]/g) ans.push_back('a'+i);
    // 	REP (i, g) {
    // 	    printf("%s", ans.c_str());
    // 	    reverse(ans.begin(), ans.end());
    // 	}
    // 	putchar('\n');

    // }

    
    return 0;
}