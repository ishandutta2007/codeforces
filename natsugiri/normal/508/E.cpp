#include<stack>
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

int N;
int L[611], R[611];
char S[2016];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", L+i, R+i);

    int P = 0;
    stack<int> X, Y;
    REP (i, N) {
	X.push(P+L[i]); Y.push(P+R[i]);
	S[P++] = '(';
	while (X.size() && X.top() <= P && P <= Y.top()) {
	    S[P++] = ')';
	    X.pop();
	    Y.pop();
	}
	if (Y.size() && Y.top() < P) {
	    puts("IMPOSSIBLE");
	    return 0;
	}
    }

    if (X.size()) puts("IMPOSSIBLE");
    else puts(S);
    
    return 0;
}