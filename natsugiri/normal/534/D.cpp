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

int N;
VI Z[200111], ans;
int main() {
    
    scanf("%d", &N);
    REP (i, N) {
	int a;
	scanf("%d", &a);
	Z[a].push_back(i);
    }

    int cur = 0;
    REP (i, N) {
	if (cur >= 3 && Z[cur-3].size() && Z[cur-2].size() && Z[cur-1].size()) cur -= 3;
	if (Z[cur].size()) {
	    ans.push_back(Z[cur].back());
	    Z[cur].pop_back();
	    cur++;
	} else {
	    break;
	}
    }

    while (cur >= 3) {
	cur -= 3;
	REP (t, 2) {
	    if (Z[cur].size()) {
		ans.push_back(Z[cur].back());
		Z[cur].pop_back();
		cur++;
	    }
	}
    }

    if ((int)ans.size() == N) {
	puts("Possible");
	REP (i, N) printf("%d%c", ans[i]+1, i+1==N? '\n': ' ');
    } else {
	puts("Impossible");
    }
    return 0;
}