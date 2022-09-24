#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)


int N;
int D[1<<16], S[1<<16];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", D+i, S+i);

    stack<int> st;
    REP (i, N) if (D[i] == 1) st.push(i);
    VI A, B;
    
    while (st.size()) {
	int v = st.top(); st.pop();
	if (D[v] != 1) continue;
	A.push_back(v);
	B.push_back(S[v]);
	D[S[v]]--;
	S[S[v]] ^= v;
	if (D[S[v]] == 1) st.push(S[v]);
    }

    printf("%d\n", (int)A.size());
    REP (i, A.size()) {
	printf("%d %d\n", A[i], B[i]);
    }
    return 0;
}