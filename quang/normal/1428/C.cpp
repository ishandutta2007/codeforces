#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        vector<int> st;
        for (char u : s) {
            if (u == 'A') st.push_back(u);
            else {
                if (st.empty()) st.push_back(u);
                else st.pop_back();
            }
        }
        cout << st.size() << '\n';
    }
    return 0;
}