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

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

char S[111];
int main() {
    scanf("%s", S);

    VI ans;
    while (true) {
	int r = 0;
	for (int i=0; S[i]; i++) {
	    r *= 10;
	    if (S[i] > '0') {
		r++;
		S[i]--;
	    }
	}
	if (r == 0) break;
	ans.push_back(r);
    }
    printf("%d\n", (int)ans.size());
    REP (i, ans.size()) printf("%d%c", ans[i], i+1 == (int)ans.size() ? '\n' : ' ');

    
    return 0;
}