#include <bits/stdc++.h>
using namespace std;
// Observation: 10 always contribute to longest subsequence by 1, so erasing them doesn't matter.
// Also, if there are no '10' substrings, then the string must be "000...00111...111", and we can
// just change it all to 0.


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string S; cin >> S;
    string T(S.size(), '-');

    stack<int> st;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '0') {
            if (st.empty()) {
                T[i] = '0';
                continue;
            }
            T[st.top()] = '1';
            T[i] = '0';
            st.pop();
        } else {
            st.push(i);
        }
    }
    while (!st.empty()) {
        T[st.top()] = '0';
        st.pop();
    }
    cout << T << "\n";
}