#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;


typedef long long LL;

int N, S[100010];
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", S+i);
    int ans=S[0]^S[1];
    
    stack<int>st;
    st.push(S[0]);
    for (int i=1; i<N; i++) {
	for (; !st.empty() && st.top()<S[i]; ) {
	    ans=max(ans, st.top()^S[i]);
	    st.pop();
	}
	if (!st.empty()) ans=max(ans, st.top()^S[i]);
	st.push(S[i]);
    }
    printf("%d\n", ans);
    return 0;
}