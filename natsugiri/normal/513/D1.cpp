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

template<class T> inline void amin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, T b) { if (a<b) a=b; }

int N, C;
int A[55], B[55];
bool LE[55];
char buf[99];

int L[111], R[111];

bool rec(int p, int q) {
    for (int i=p+1; i<=q+1; i++) { // p [p+1..i-1] [i..q]
	bool ok = true;
	REP (k, C) {
	    if (p+1 <= A[k] && A[k] <= i-1 && i <= B[k] && B[k] <= q) ok = false;
	    if (p == A[k]) {
		if (LE[k] && !(p+1 <= B[k] && B[k] <= i-1)) ok = false;
		if (!LE[k] && !(i <= B[k] && B[k] <= q)) ok = false;
	    }
	}

	if (ok) {
	    bool tmp = true;
	    if (i != p+1) {
		L[p] = p+1;
		tmp = (tmp && rec(p+1, i-1));
	    }
	    if (i != q+1) {
		R[p] = i;
		tmp = (tmp && rec(i, q));
	    }
	    return tmp;
	}
    }

    return false;
}

vector<int> ans;
void inord() {
    stack<int> st;
    st.push(1);
    while (!st.empty()) {
	int x = st.top(); st.pop();
	if (x == 0) continue;
	if (x > 0) {
	    st.push(-x);
	    st.push(L[x]);
	} else {
	    ans.push_back(-x);
	    st.push(R[-x]);
	}
    }
}

int main() {
    scanf("%d%d", &N, &C);
    REP (i, C) {
	scanf("%d%d%s", A+i, B+i, buf);
	if (buf[0] == 'L') LE[i] = true;
    }

    // memset(L, -1, sizeof L);
    // memset(R, -1, sizeof R);
    bool ok = rec(1, N);

    if (!ok) puts("IMPOSSIBLE");
    else {
	inord();
	REP (i, N) printf("%d%c", ans[i], i+1==N ? '\n':' ');
    }
    
    return 0;
}