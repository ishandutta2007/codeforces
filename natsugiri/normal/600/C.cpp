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


char buf[200011];
int cnt[26];

int main() {
    scanf("%s", buf);
    int n = strlen(buf);
    REP (i, n) cnt[buf[i] - 'a']++;

    REP (i, 26) if (cnt[i] & 1) {
	int p = -1;
	REP (j, 26) if (cnt[j] & 1) p = j;
	if (p != -1) {
	    cnt[i]++;
	    cnt[p]--;
	}
    }

    REP (i, 26) REP (j, cnt[i]/2) putchar('a'+i);
    REP (i, 26) if (cnt[i] & 1) putchar('a'+i);
    REP (i, 26) REP (j, cnt[25-i]/2) putchar('z'-i);
    putchar('\n');

    return 0;
}