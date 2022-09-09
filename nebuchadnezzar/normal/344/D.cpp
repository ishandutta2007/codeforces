#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <string.h>
#include <stack>

using namespace std;

string s;
stack <char> st;

int main() {
    cin >> s;
    if (s.length() % 2 != 0) {
        cout << "No";
        return 0;
    }

    for (int i = 0; i < (int) s.length(); ++i) {
        if (st.size() > 0 && st.top() == s[i]) {
            st.pop();
        } else {
            st.push(s[i]);
        }
    }

    if (st.size() == 0) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    

    return 0;
}