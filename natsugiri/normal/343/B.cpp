#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<stack>
using namespace std;

typedef long long LL;


int main() {
    string S;
    cin >> S;
    stack<char>st;
    for (int i=0; i<int(S.size()); i++) {
	if (st.empty() || st.top() != S[i]) st.push(S[i]);
	else st.pop();
    }

    puts(st.empty() ? "Yes" : "No");
    return 0;
}