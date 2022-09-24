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


int N;
char S[111];
int main() {
    scanf("%d%s", &N, S);

    VI ans;
    char pre = 'W';
    int cnt = 0;
    REP (i, N) {
	if (S[i] == 'W' && pre == 'B') {
	    ans.push_back(cnt);
	    cnt = 0;
	} else if (S[i] == 'B') {
	    cnt++;
	}

	pre = S[i];
    }

    if (pre == 'B') ans.push_back(cnt);

    printf("%d\n", (int)ans.size());
    REP (i, ans.size()) printf("%d%c", ans[i], i==(int)ans.size()-1? '\n': ' ');

    return 0;
}