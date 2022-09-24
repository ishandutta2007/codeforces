#include<set>
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


int N, M;
int X;
char S[300111], op[8];

int main() {
    scanf("%d%d",& N, &M);
    scanf("%s", S);
    int ans = 0;
    int cnt = 0;
    for (int i=0; ; i++) {
	if (S[i] == '.') cnt++;
	else {
	    if (cnt > 1) ans += cnt-1;
	    cnt = 0;
	}
	if (S[i] == 0) break;
    }


    REP ($, M) {
	scanf("%d%s", &X, op);
	X--;
	bool l, r;
	l = (X > 0 && S[X-1] == '.');
	r = (X+1 < N && S[X+1] == '.');
	
	if (op[0] == '.') {
	    if (S[X] != '.') {
		if (l && r) ans += 2;
		else if (l || r) ans += 1;
	    }
	} else {
	    if (S[X] == '.') {
		if (l && r) ans -= 2;
		else if (l || r) ans -= 1;
	    }
	}
	S[X] = op[0];
	
	printf("%d\n", ans);
    }
    
    return 0;
}