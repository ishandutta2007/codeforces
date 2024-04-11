#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;

typedef long long LL;

int N, P[1000010], T, Q[1000010], X[1000010];

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", P+i);
    scanf("%d", &T);
    for (int i=0; i<T; i++) { scanf("%d", Q+i); Q[i]--; }
    sort(Q, Q+T);

    memset(X, -1, sizeof X);
    
    for (int i=0; i<T; i++) {
	int k=Q[i];
	stack<int> st;
	st.push(k);
	for (;k--;) {
	    if (X[k]!=-1) k=X[k];
	    else {
		int e=st.top();
		if (P[e]==P[k]) {
		    X[e]=k; X[k]=e;
		    st.pop();
		    if (st.empty()) break;
		} else {
		    st.push(k);
		}
	    }
	}
	if (!st.empty()) {
	    puts("NO");
	    return 0;
	}
    }
    //for (int i=0; i<N; i++) printf("%d%c", X[i], i+1==N?'\n':' ');
    stack<int>st;
    for (int k=0; k<N; k++) {
	if (X[k]==-1) {
	    if (st.empty() || P[st.top()]!=P[k]) st.push(k);
	    else {
		int e=st.top(); st.pop();
		X[e]=k; X[k]=e;
	    }
	} else k=X[k];
    }

    if (st.empty()) {
	puts("YES");
	for (int i=0; i<N; i++) printf("%d%c", i<X[i]?P[i]:-P[i], i+1==N?'\n':' ');

    } else puts("NO");

    return 0;
}